using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace OnlineBookOrdering.Models
{
    public class Book
    {
       // [DatabaseGenerated(DatabaseGeneratedOption.None)] //autoincrement = false
        public int BookID { get; set; }
        public string BookTitle { get; set; }
        public string BookAuthor { get; set; }
        public string BookGenre { get; set; }

        [DisplayName("Book Price")]
        public double BookPrice { get; set; }
        public int BookQuantity { get; set; }

        public virtual ICollection<Order> Orders { get; set; }
    }
}