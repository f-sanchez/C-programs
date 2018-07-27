using AllianceUniversity.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace AllianceUniversity.Controllers
{
    public class StudentController : Controller
    {
        List<Student> studentList = new List<Student>
        {
            new Student(){ StudentId = 1, StudentName = "John", Age = 16},
            new Student(){ StudentId = 2, StudentName = "Ivan", Age = 21},
            new Student(){ StudentId = 3, StudentName = "Justin", Age = 21},
            new Student(){ StudentId = 4, StudentName = "Fretzel", Age = 22},
            new Student(){ StudentId = 5, StudentName = "Chris", Age = 17},
            new Student(){ StudentId = 1, StudentName = "Rodger", Age = 16},
            new Student(){ StudentId = 2, StudentName = "Evan", Age = 21},
            new Student(){ StudentId = 3, StudentName = "Marc", Age = 21},
            new Student(){ StudentId = 4, StudentName = "Kris", Age = 22},
            new Student(){ StudentId = 5, StudentName = "Panda", Age = 17}
        };

        // GET: Student
        public ActionResult Index()
        {

            return View(studentList);
        }

       /*
        
        [HttpGet]
        public ActionResult Edit()
        {
            var id = Request.QueryString["id"];

            return View();
        }
        */

        [HttpGet]
        public ActionResult Edit(int id)
        {
            var std = studentList.Where(s => s.StudentId == id).FirstOrDefault();

            return View(std);
        }

        [HttpPost]
        public ActionResult Edit(Student stud)
        {
            var id = Request.QueryString["id"];

            return RedirectToAction("Index");
        }
    }
}
 