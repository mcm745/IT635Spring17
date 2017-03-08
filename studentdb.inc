<?php

class StudentAccess
{
  private $db;

#echo "successfully connected\n";
#echo "successfully connected".PHP_EOL;

public function __construct($database)
{
  $this->db = new mysqli("localhost", "root", "1234", $database);

  if ($this->db->connect_errno != 0)
  {
   echo "error connecting to database: ".$this->db->connect_error.PHP_EOL;
   exit();
  }
}

public function __destruct()
{
  if (isset($this->db))
  {
   $this->db->close();
  }
}

public function getStudentRecords()
{
  $query = "select * from class;";

  $queryResponse = $this->db->query($query);
  $respone = array();

  #print_r($queryResponse);

   while($row = $queryResponse->fetch_assoc())
   {
    #print_r($row);
    $response[] = ($row);
   }
   return $response;
}

public function addStudentRecord($studentName, $id, $address, $year)
{
  $query = "insert into class(student, ID, address, year) values ('$studentName', '$id', '$address', '$year');";

  if (!$this->db->query($query))
  {
    echo "failed to insert record for $studentName".PHP_EOL;
  }
}
}
?>
