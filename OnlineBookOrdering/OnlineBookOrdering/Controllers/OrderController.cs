using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using OnlineBookOrdering.DAL;
using OnlineBookOrdering.Models;
using PagedList;

namespace OnlineBookOrdering.Controllers
{
    public class OrderController : Controller
    {
        private OrderContext db = new OrderContext();

        // GET: Order
        public ActionResult Index(string sortOrder, string searchString, int? page)
        {
            ViewBag.NameSortParam = String.IsNullOrEmpty(sortOrder) ? "name_desc" : "";
            ViewBag.TitleSortParam = sortOrder == "BookTitle" ? "title_desc" : "BookTitle";
            ViewBag.OrdrQtySortParam = sortOrder == "OrderQuantity" ? "ordrqty_desc" : "OrderQuantity";
            ViewBag.DateSortParam = sortOrder == "Date" ? "date_desc" : "Date";

            var orders = from c in db.Orders.Include(o => o.Book).Include(o => o.Customer)
                         select c;
            if (!string.IsNullOrEmpty(searchString))
            {
                orders = orders.Where(c => c.Book.BookTitle.Contains(searchString)
                    || c.Book.BookTitle.Contains(searchString));
            }

            switch (sortOrder)
            {
                case "name_desc":
                    orders = orders.OrderByDescending(c => c.Customer.FirstName);
                    break;
                case "title_desc":
                    orders = orders.OrderByDescending(c => c.Book.BookTitle);
                    break;
                case "ordrqty_desc":
                    orders = orders.OrderByDescending(c => c.OrderQuantity);
                    break;
                case "date_desc":
                    orders = orders.OrderByDescending(c => c.OrderDate);
                    break;
                case "BookTitle":
                    orders = orders.OrderBy(c => c.Book.BookTitle);
                    break;
                case "OrderQuantity":
                    orders = orders.OrderBy(c => c.OrderQuantity);
                    break;
                case "Date":
                    orders = orders.OrderBy(c => c.OrderDate);
                    break;
                default:
                    orders = orders.OrderBy(c => c.Customer.LastName);
                    break;
            }

            int pageSize = 5;
            int pageNumber = (page ?? 1);

            //return View(db.Books.ToList());
            return View(orders.ToPagedList(pageNumber, pageSize));
           // return View(orders.ToList());
        }

        // GET: Order/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Order order = db.Orders.Find(id);
            if (order == null)
            {
                return HttpNotFound();
            }
            return View(order);
        }

        // GET: Order/Create
        public ActionResult Create()
        {
            ViewBag.BookID = new SelectList(db.Books, "BookID", "BookTitle");
            ViewBag.CustomerID = new SelectList(db.Customers, "ID", "FirstName");

            return View();
        }

        // POST: Order/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "OrderID,OrderQuantity,CustomerID,BookID")] Order order)
        {
            if (ModelState.IsValid)
            {
                Book b = db.Books.Find(order.BookID);
                b.BookQuantity -= order.OrderQuantity;
                order.TotalPrice = order.OrderQuantity * b.BookPrice;
                db.Entry(b).State = EntityState.Modified;

                order.OrderDate = DateTime.Now;
                db.Orders.Add(order);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            ViewBag.BookID = new SelectList(db.Books, "BookID", "BookTitle", order.BookID);
            ViewBag.CustomerID = new SelectList(db.Customers, "ID", "FirstName", order.CustomerID);
            return View(order);
        }

        // GET: Order/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Order order = db.Orders.Find(id);
            if (order == null)
            {
                return HttpNotFound();
            }
            ViewBag.BookID = new SelectList(db.Books, "BookID", "BookTitle", order.BookID);
            ViewBag.CustomerID = new SelectList(db.Customers, "ID", "FirstName", order.CustomerID);
            return View(order);
        }

        // POST: Order/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "OrderID,OrderQuantity,BookTitle,CustomerID,BookID")] Order order)
        {
            if (ModelState.IsValid)
            {
                order.OrderDate = DateTime.Now;
                db.Entry(order).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            ViewBag.BookID = new SelectList(db.Books, "BookID", "BookTitle", order.BookID);
            ViewBag.CustomerID = new SelectList(db.Customers, "ID", "FirstName", order.CustomerID);
            return View(order);
        }

        // GET: Order/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Order order = db.Orders.Find(id);
            if (order == null)
            {
                return HttpNotFound();
            }
            return View(order);
        }

        // POST: Order/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Order order = db.Orders.Find(id);
            db.Orders.Remove(order);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
