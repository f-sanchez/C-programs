namespace OnlineBookOrdering.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class initial1 : DbMigration
    {
        public override void Up()
        {
            DropPrimaryKey("dbo.Book");
            AddColumn("dbo.Book", "BookTitle", c => c.String());
            AlterColumn("dbo.Book", "BookID", c => c.Int(nullable: false));
            AddPrimaryKey("dbo.Book", "BookID");
        }
        
        public override void Down()
        {
            DropPrimaryKey("dbo.Book");
            AlterColumn("dbo.Book", "BookID", c => c.Int(nullable: false, identity: true));
            DropColumn("dbo.Book", "BookTitle");
            AddPrimaryKey("dbo.Book", "BookID");
        }
    }
}
