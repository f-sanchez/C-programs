namespace OnlineBookOrdering.Migrations
{
    using OnlineBookOrdering.Models;
    using System;
    using System.Collections.Generic;
    using System.Data.Entity;
    using System.Data.Entity.Migrations;
    using System.Linq;

    internal sealed class Configuration : DbMigrationsConfiguration<OnlineBookOrdering.DAL.OrderContext>
    {
        public Configuration()
        {
            AutomaticMigrationsEnabled = false;
        }

        protected override void Seed(OnlineBookOrdering.DAL.OrderContext context)
        {
            //  This method will be called after migrating to the latest version.

            //  You can use the DbSet<T>.AddOrUpdate() helper extension method 
            //  to avoid creating duplicate seed data.

            if (!context.Customers.Any())
            {
                var customer = new List<Customer>
                {
                    new Customer{FirstName="Fretzel", LastName="Sanchez"},
                    new Customer{FirstName="Justin", LastName="Enerio"},
                    new Customer{FirstName="Ivan Rodger", LastName="Apos"},
                    new Customer{FirstName="Hermione", LastName="Granger"},
                    new Customer{FirstName="Chandler", LastName="Bing"},
                    new Customer{FirstName="Holden", LastName="Scolfield"},
                    new Customer{FirstName="Michael", LastName="Scofield"},
                    new Customer{FirstName="Jazz", LastName="Jazz"},
                    new Customer{FirstName="Nestle", LastName="Milo"},
                    new Customer{FirstName="Panda", LastName="Bear"}
                };

                customer.ForEach(c => context.Customers.Add(c));
                context.SaveChanges();
            }

            if (!context.Books.Any())
            {
                var books = new List<Book>
                {
                    new Book{BookTitle="Harry Potter and the Sorcerer's Stone", BookAuthor="JK Rowling", BookGenre="Fantasy"},
                    new Book{BookTitle="Looking for Alaska", BookAuthor="John Green", BookGenre="Mystery"},
                    new Book{BookTitle="The Catcher in the Rye", BookAuthor="JD Salinger", BookGenre="Young Adult"},
                    new Book{BookTitle="Harry Potter and the Chamber of Secrets", BookAuthor="JK Rowling", BookGenre="Fantasy"},
                    new Book{BookTitle="Harry Potter and the Prisoner of Azkaban", BookAuthor="JK Rowling", BookGenre="Fantasy"},
                    new Book{BookTitle="Crime and Punishment", BookAuthor="Fyodor Dostoyevsky", BookGenre="Russian Classics"},
                    new Book{BookTitle="The Little Prince", BookAuthor="Anon", BookGenre="Children's"},
                    new Book{BookTitle="Rich Dad Poor Dad", BookAuthor="------", BookGenre="Business"}
                   // new Book{BookTitle="Harry Potter", BookAuthor="JK Rowling", BookGenre="Fantasy"},
                   // new Book{BookTitle="Harry Potter", BookAuthor="JK Rowling", BookGenre="Fantasy"},
                };

                books.ForEach(c => context.Books.Add(c));
                context.SaveChanges();
            }

            //if (!context.Orders.Any())
            //{
            //    var orders = new List<Order>
            //    {
            //        new Order{OrderQuantity=1, OrderDate=DateTime.Parse("2018-07-30")},
            //        new Order{OrderQuantity=2, OrderDate=DateTime.Parse("2018-07-23")},
            //        new Order{OrderQuantity=1, OrderDate=DateTime.Parse("2018-07-21")},
            //        new Order{OrderQuantity=3, OrderDate=DateTime.Parse("2018-07-01")},
            //        new Order{OrderQuantity=1, OrderDate=DateTime.Parse("2018-07-23")},
            //        new Order{OrderQuantity=1, OrderDate=DateTime.Parse("2018-07-01")},
            //        new Order{OrderQuantity=5, OrderDate=DateTime.Parse("2018-07-30")},
            //    };
            //}
        }
    }
}
