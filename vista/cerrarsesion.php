<?php
# Aseguramos desactivar todas las sesiones:
unset($_SESSION["logged"]);
unset($_SESSION["perf"]);
# Destruimos todos los archivos y variables de la sesion:
session_destroy();
# Destruimos los cookies del navegador para que al dar atrás no 
$parametros_cookies = session_get_cookie_params(); 
setcookie(session_name(),0,1,$parametros_cookies["path"]);
# Actualizamos la pagina donde nos escontrabamos y redirigimos a la pagina princial
echo "<meta http-equiv='refresh' content='0;'/>";
header('location:../index.php');
exit;
?>

