# Database
Simple PHP PDO Database Class with built-in query function 



## Configuration

Visit the configuration file to set the name of the database, username, password and Host;

## Start

Start by getting an instance of the database then call query();

```
$db = Database::getInstance();

$res = $db->query('select * from User','all',[$id],false);
```

or you can simply get an instance and be incharge of your on query

```
$db = Database::getInstance();

$pdo = $db->getConnection();

$res = $pdo->query('select * from User');
```

## First Param

To query the Database simply pass the query as first parameter like this:

```
$db->query('select * from User');
```

## Second Param

Tell the function if you want it to return it All rows with keyword 'all';
```
$db->query('select * from User', 'all');
```

Pass a empty string otherwise;

```
$db->query('select * from User', '');
```

## Third Param

Pass variables to be binded to your query in a array fashion. You

```
$db->query('select * from User where id = ?', '' , [$id]);

or

$db->query('select * from User where id = :id', '' , [':id'=>'']);
```

## Forth Param

If you just want to know if the query was excuted correctly pass 'false' as last parameter. Default is true.
This is good for update and insert queries.

```
$db->query('Update table User set name = ?', '' , [$id], false);
```

