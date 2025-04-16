<?php

class DB{
    protected $dbType, $dbName, $host, $connection, $userName, $userPassword;

    function __construct($dbType, $dbName, $host, $userName, $userPassword)
    {
        $this->dbType = $dbType;
        $this->dbName = $dbName;
        $this->host = $host;
        $this->userName = $userName;
        $this->userPassword = $userPassword;
        $this->connection = new PDO("$this->dbType:host=$this->host;dbname=$this->dbName", $this->userName, $this->userPassword);
    }
    public function query($sql){
        return $this->connection->query($sql);
    }
    function connection(){
        return $this->connection;
    }
    /**=========== Get All Users ============ */
    function getAllUsers($table){
        $alldata = "select * from $table";
        $sqlQuery = $this->connection->prepare($alldata);
        $sqlQuery->execute();
        $result = $sqlQuery->fetchAll(PDO::FETCH_ASSOC);
        if ($result) {
            return $result;
        } else {
            echo "Data Empty";
        }
    }
    function getUser($table,$id){
        try {
            $query = "select * from $table where id=$id";
            $sqlQuery = $this->connection->prepare($query);
            $sqlQuery->execute();
            return $sqlQuery->fetch(PDO::FETCH_ASSOC);
           } catch (Error $e) {
      
            return null;
           }
    }
    function delete($table, $id)
    {
       try {
        $query = "delete from $table where id=$id";
        $sqlQuery = $this->connection->prepare($query);
        $sqlQuery->execute();
        return $sqlQuery->fetch(PDO::FETCH_ASSOC);
       } catch (Error $e) {
        return null;
       }
    }
    // function insertData($table,$data){
    //     $sqlQuery = $this->connection->prepare("INSERT INTO $table SET ");
    //     $sqlQuery->execute($data);
    //     return $this->connection->lastInsertId();
    // }

    
    
}
$dataBase = new DB(dbType:'mysql',host:"localhost",dbName:"os-data-2025",userName:"root",userPassword:"1234");
// var_dump($dataBase);
?>