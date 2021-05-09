
<h4>Why Document Store vs Sql</h4>
	<ol>
	  <li>NodeJS people like it. NodeJs is more favourable to use with NOSql</li>
	  <li>Complex Structure of data </li>
    <li><b>Hierarical Structure of data</b></li>
	</ol>
<h4>Properties</h4>
<ol>
  <li>
    Document oriented database
  </li>
  <li>
    Key Terms
    <ol>
      <li>
        <b>Database</b> - It is a physical container for collections. Each database gets its own set of files on the file system. A single MongoDB server typically has multiple databases.
      </li>
      <li>
        <b>Collection</b> - It is the equivalent of an RDBMS table. A collection exists within a single database.
      </li>
      <li>
        <b>Document</b> - A document is a set of key-value pairs.
      </li>
      <li>
        <table style="text-align:center;" class="table table-bordered">
          <tr>
            <th style="text-align:center;width:50%;">RDBMS</th>
            <th style="text-align:center;">MongoDB</th>
          </tr>
          <tr>
            <td>Database</td>
            <td>Database</td>
          </tr>
          <tr>
            <td>Table</td>
            <td>Collection</td>
          </tr>
          <tr>
           <td>Tuple/Row</td>
           <td>Document</td>
          </tr>
          <tr>
            <td>column</td>
            <td>Field</td>
          </tr>
          <tr>
            <td>Table Join</td>
            <td>Embedded Documents</td>
          </tr>
          <tr>
            <td>Primary Key</td>
            <td>Primary Key (Default key _id provided by MongoDB itself)</td>
          </tr>
          <tr>
            <th colspan="2" style="text-align:center;">Database Server and Client</th>
          </tr>
          <tr>
          <td>mysqld/Oracle</td>
          <td>mongod</td>
          </tr>
          <tr>
          <td>mysql/sqlplus</td>
          <td>mongo</td>
          </tr>
         </table>
      </li>
      </li>
</ol>
</ol>
Datatypes in Mongoose
<ol>
	<li> Numerals </li> 
	<li> Boolean </li>
	<li> Array </li>
	<li> Mixed </li> 
	<li> Object </li>
</ol>
<h4>Todo</h4>
<ol>
  <li>Create DB at mongoDB cloud</li>
  <li>Connection of MongoDB with express framework</li> 
  </ol>
