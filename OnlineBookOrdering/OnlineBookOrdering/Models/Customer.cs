using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace OnlineBookOrdering.Models
{
    public class Customer
    {
        public int ID { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }

        public virtual ICollection<Order> Orders { get; set; }
    }
}