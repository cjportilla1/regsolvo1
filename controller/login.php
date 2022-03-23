<?php  
 session_start();
 # Si oprimimos el boton de loginuser, vamos a validar el ingreso:
if (isset($_POST['btnlogin'])){
     # Incluyo la conexion a la base de datos:
      // print_r($_POST);
 require('../vista/conexion.php');
 date_default_timezone_set('Etc/GMT+5');



 $con = New Conexion();
 $createcon=$con->conectar();
  $createcon->set_charset("utf8");

     # Capturo los datos del formulario:
 $user = $_POST['user'];
 $pass = $_POST['passuser'];

     # Estructuramos la consulta SQL:
 $sql = "call sp_login('".$user."','".$pass."')";
 $exe = $createcon->query($sql);

 # Ejecutamos la consulta:
 $res=$exe->fetch_row();

 
   if($exe->num_rows>0 and $res[0]!='error'){

   switch ($res[1]) {
       case '1':
        $_SESSION["usuar"]=$res[0];
        $_SESSION["usnombre"]=$res[2];
        $_SESSION["usapell"]=$res[3];
        $_SESSION["perf"]='admin';
        $_SESSION["logged"]=1;
        $_SESSION["solvid"]=$res[5];

        echo "1";

        // print_r($res[0]);
        # code...
        break;

        case '2':
            $_SESSION["usuar"]=$res[0];
            $_SESSION["usnombre"]=$res[2];
            $_SESSION["usapell"]=$res[3];
            $_SESSION["perf"]='supervisor';
            $_SESSION["logged"]=1;
            $_SESSION["solvid"]=$res[5];
            echo "1";
    
            break;

            case '3':
                $_SESSION["usuar"]=$res[0];
                $_SESSION["usnombre"]=$res[2];
                $_SESSION["usapell"]=$res[3];
                $_SESSION["perf"]='colaborador';
                $_SESSION["logged"]=1;
                $_SESSION["solvid"]=$res[5];
                echo "1";
       
       default:
           # code...
          
             }

	}   else {
        print_r('error en al consulta');
    }
}

?>