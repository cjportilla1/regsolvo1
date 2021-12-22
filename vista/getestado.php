<?php
require("conexion.php");

$idpais=$_POST["idpais"];

$sqle = "select idEst,nomEstado from Testado where idPais=?";
$datos = array(
    array($idpais, SQLSRV_PARAM_IN),
);
$resu = sqlsrv_query($con, $sqle, $datos);

$html="<option value='0'> seleccione pais</option>";

while ($row = sqlsrv_fetch_array($resu, SQLSRV_FETCH_BOTH)) {
  $html='<option value="' . $row["idEst"] . '">' . $row["nomEstado"] . '</option>';
  echo $html;
}



