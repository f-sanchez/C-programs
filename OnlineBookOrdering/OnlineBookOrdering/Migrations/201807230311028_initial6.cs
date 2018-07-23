namespace OnlineBookOrdering.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class initial6 : DbMigration
    {
        public override void Up()
        {
            AddColumn("dbo.Order", "Book_BookID", c => c.Int());
            AddColumn("dbo.Order", "Customer_ID", c => c.Int());
            CreateIndex("dbo.Order", "Book_BookID");
            CreateIndex("dbo.Order", "Customer_ID");
            AddForeignKey("dbo.Order", "Book_BookID", "dbo.Book", "BookID");
            AddForeignKey("dbo.Order", "Customer_ID", "dbo.Customer", "ID");
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.Order", "Customer_ID", "dbo.Customer");
            DropForeignKey("dbo.Order", "Book_BookID", "dbo.Book");
            DropIndex("dbo.Order", new[] { "Customer_ID" });
            DropIndex("dbo.Order", new[] { "Book_BookID" });
            DropColumn("dbo.Order", "Customer_ID");
            DropColumn("dbo.Order", "Book_BookID");
        }
    }
}
