Select BusinessEntityID, firstname, lastname
into #TempPersonTable
from [Person].[Person] where title = 'mr.'
