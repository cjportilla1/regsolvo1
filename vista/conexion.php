<?PHP

Class Conexion {

public function conectar() {
   return new mysqli("localhost", "root", "", "regsolvo");
//    if (mysqli_connect_errno()) {
//       printf("Conexión fallida: %s\n", mysqli_connect_error());
//       exit();
//   }
    
}

}

?>


