namespace OnlineBookOrdering.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class bookprice : DbMigration
    {
        public override void Up()
        {
            AddColumn("dbo.Book", "BookPrice", c => c.Double(nullable: false));
            AddColumn("dbo.Order", "TotalPrice", c => c.Double(nullable: false));
        }
        
        public override void Down()
        {
            DropColumn("dbo.Order", "TotalPrice");
            DropColumn("dbo.Book", "BookPrice");
        }
    }
}
