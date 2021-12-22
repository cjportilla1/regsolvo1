<?php
// $serverName="localhost";

// $connectionInfo = array("Database"=>"modulos180920","UID"=>"cris2","PWD"=>"asdf","CharacterSet"=>"UTF-8");
// $con = sqlsrv_connect($serverName,$connectionInfo);

// if($con){
// echo "db ok";

// } 
// else {
//     print_r(sqlsrv_errors());
// }

?>


<!-- CONEXION CON MYSQL -->
<?PHP

Class Conexion {

public function conectar() {
   return new mysqli("localhost", "root", "", "regsolvo");
    
}

}

?>


 <?php
// $connectionInfo = array("UID" => "cris2", "pwd" => "EnergyMaster2020*", "Database" => "modulos09092020", "LoginTimeout" => 30, "Encrypt" => 1, "TrustServerCertificate" => 0,"CharacterSet"=>"UTF-8");

// $serverName = "tcp:modserver.database.windows.net,1433";

// $con = sqlsrv_connect($serverName, $connectionInfo);

?> 