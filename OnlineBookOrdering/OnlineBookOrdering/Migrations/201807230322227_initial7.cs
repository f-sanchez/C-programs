namespace OnlineBookOrdering.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class initial7 : DbMigration
    {
        public override void Up()
        {
            DropForeignKey("dbo.Order", "Book_BookID", "dbo.Book");
            DropForeignKey("dbo.Order", "Customer_ID", "dbo.Customer");
            DropIndex("dbo.Order", new[] { "Book_BookID" });
            DropIndex("dbo.Order", new[] { "Customer_ID" });
            RenameColumn(table: "dbo.Order", name: "Book_BookID", newName: "BookID");
            RenameColumn(table: "dbo.Order", name: "Customer_ID", newName: "CustomerID");
            AlterColumn("dbo.Order", "BookID", c => c.Int(nullable: false));
            AlterColumn("dbo.Order", "CustomerID", c => c.Int(nullable: false));
            CreateIndex("dbo.Order", "CustomerID");
            CreateIndex("dbo.Order", "BookID");
            AddForeignKey("dbo.Order", "BookID", "dbo.Book", "BookID", cascadeDelete: true);
            AddForeignKey("dbo.Order", "CustomerID", "dbo.Customer", "ID", cascadeDelete: true);
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.Order", "CustomerID", "dbo.Customer");
            DropForeignKey("dbo.Order", "BookID", "dbo.Book");
            DropIndex("dbo.Order", new[] { "BookID" });
            DropIndex("dbo.Order", new[] { "CustomerID" });
            AlterColumn("dbo.Order", "CustomerID", c => c.Int());
            AlterColumn("dbo.Order", "BookID", c => c.Int());
            RenameColumn(table: "dbo.Order", name: "CustomerID", newName: "Customer_ID");
            RenameColumn(table: "dbo.Order", name: "BookID", newName: "Book_BookID");
            CreateIndex("dbo.Order", "Customer_ID");
            CreateIndex("dbo.Order", "Book_BookID");
            AddForeignKey("dbo.Order", "Customer_ID", "dbo.Customer", "ID");
            AddForeignKey("dbo.Order", "Book_BookID", "dbo.Book", "BookID");
        }
    }
}
