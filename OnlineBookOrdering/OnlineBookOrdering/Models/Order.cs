using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace OnlineBookOrdering.Models
{
    public class Order
    {
        public int OrderID { get; set; }
        public int OrderQuantity { get; set; }
        public DateTime OrderDate { get; set; }

        public int CustomerID { get; set; }
        [ForeignKey("CustomerID")]
        public virtual Customer Customer { get; set; }

        public int BookID { get; set; }
        [ForeignKey("BookID")]
        public virtual Book Book { get; set; }

        [DisplayName("Total Price")]
        public double TotalPrice { get; set; }
    }


}