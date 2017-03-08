#!/usr/bin/php
<?php

require_once("studentdb.inc");

# argv[0] - name of the script being executed
echo "executing script: ".$argv[].PHP_EOL;

#echo "successfully connected\n";
#echo "successfully connected".PHP_EOL;

$studentDB = new StudentAccess("Classes");

$students = $studentDB->getStudentRecords();
echo "student records in db are:".PHP_EOL;
print_r($students);
echo $argv[0]." complete".PHP_EOL;
?>
