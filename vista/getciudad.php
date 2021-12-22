<?php
require("conexion.php");

$idciudad=$_POST["idciudad"];

$sqle = "select idCity,nomCity from Tcity where idEstado=?";
$datos = array(
    array($idciudad, SQLSRV_PARAM_IN),
);
$resuc = sqlsrv_query($con, $sqle, $datos);

$html="<option value='0'> seleccione pais</option>";

while ($rowc = sqlsrv_fetch_array($resuc, SQLSRV_FETCH_BOTH)) {
  $html='<option value="' . $rowc["idCity"] . '">' . $rowc["nomCity"] . '</option>';
  echo $html;
}
