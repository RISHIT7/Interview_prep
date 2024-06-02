create trigger [schema_name.]trigger_name
on table_name
after {[insert].[delete].[update]}
[not for replication]
as 
{sql_statements}

create trigger afterdeletetrigger on triggerdemo_parent
after delete
as insert into triggerdemo_history values ((select top 1 id from triggerdemo_parent), 'delete')
go
