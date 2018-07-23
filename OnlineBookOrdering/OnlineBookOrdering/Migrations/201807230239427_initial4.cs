namespace OnlineBookOrdering.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class initial4 : DbMigration
    {
        public override void Up()
        {
            DropPrimaryKey("dbo.Book");
            AlterColumn("dbo.Book", "BookID", c => c.Int(nullable: false, identity: true));
            AddPrimaryKey("dbo.Book", "BookID");
        }
        
        public override void Down()
        {
            DropPrimaryKey("dbo.Book");
            AlterColumn("dbo.Book", "BookID", c => c.Int(nullable: false));
            AddPrimaryKey("dbo.Book", "BookID");
        }
    }
}
