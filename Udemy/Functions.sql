CREATE Function [database_name.]function_name (parameters)
RETURNS data_type as
begin
SQL statments
return value
end;

-- example
create function getEmpFullName (
  @firat_name varchar(50), @last_name varchar(50)
)
returns varchar(101)
as begin
return (select @first_name + ' ' + @last_name)
end

-- immutable
create function fnGetMulEmployee()
returns @Emp table
(
  Empid int,
  FirstName varchar(50),
  Salary int
)
AS 
begin
 insert into @Emp Select e.EmpID, e.FirstName, e.LastName, e.Salary from functionEmployee e;
 -- now update the salary of the first employee
 update @Emp set Salary = 25000 where EmpID = 1;
 -- will onlu update the salary in the @Emp table not in the orginal employee table
return
end

select * from dbo.fnGetMulEmployee(); -- udpate salary
select * from dbo.functionEmployee(); -- not updated
