<?php
include("../vista/conexion.php");
   $con = New Conexion();
   $createcon=$con->conectar();
   $createcon->set_charset("utf8");



// $sql = "SELECT * FROM usuario";
// $exe = $conectar->query($sql);

// error_reporting(0);


# code...
if ($_POST['btnopcion'] == 'guardar') {



	$nom = ucwords($_POST['nombre']);
	$nombre = trim($nom);
	$documento = trim($_POST['cedula']);
	$fnacimiento  = $_POST['fnacimiento'];
	$ciudadr = $_POST['cresidencia'];
	$ciudadn = $_POST['cnacimiento'];
	$rol = $_POST['cargo'];
	$tel = $_POST['telefono'];
	$nomcont = ucwords($_POST['contacto']);
	$contacto = trim($nomcont);
	$telconta = $_POST['telefonoc'];
	$rh = $_POST['rhsanguineo'];
	$idtipodoc = $_POST['idTipoDoc'];
	$mtransporte = $_POST['medtransporte'];
	$direccion = trim($_POST['direccion']);
	$genero = $_POST['genero'];
	$fingreso = $_POST['fingreso'];
	$computador = trim($_POST['computador']);
	$idemail = $_POST['idemail'];



	$sql = "exec sp_insertar ?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?";
	$datos = array(
		array($nombre, SQLSRV_PARAM_IN),
		array($documento, SQLSRV_PARAM_IN),
		array($fnacimiento, SQLSRV_PARAM_IN),
		array($ciudadn, SQLSRV_PARAM_IN),
		array($rol, SQLSRV_PARAM_IN),
		array($tel, SQLSRV_PARAM_IN),
		array($contacto, SQLSRV_PARAM_IN),
		array($telconta, SQLSRV_PARAM_IN),
		array($idtipodoc, SQLSRV_PARAM_IN),
		array($ciudadr, SQLSRV_PARAM_IN),
		array($direccion, SQLSRV_PARAM_IN),
		array($rh, SQLSRV_PARAM_IN),
		array($mtransporte, SQLSRV_PARAM_IN),
		array($genero, SQLSRV_PARAM_IN),
		array($fingreso, SQLSRV_PARAM_IN),
		array($computador, SQLSRV_PARAM_IN),
		array($idemail, SQLSRV_PARAM_IN)

	);




	// $exe = $con->query($sql);
	$res = sqlsrv_query($con, $sql, $datos);

	// 		print_r($_POST);
	// print_r(sqlsrv_errors());

	while ($row = sqlsrv_fetch_array($res)) {



		if ($row[0] != 'error') {

			echo "datos registrados correctamente";
		} else {
			echo "error , campos vacios,registro duplicado ó errores de datos";
		}
	}
}

if ($_POST['btnopcion'] == 'actualizar') {



	$nom = ucwords($_POST['nombre']);
	$nombre = trim($nom);
	$documento = trim($_POST['cedula']);
	$fnacimiento  = $_POST['fnacimiento'];
	$ciudadr = $_POST['cresidencia'];
	$ciudadn = $_POST['cnacimiento'];
	$rol = $_POST['cargo'];
	$tel = $_POST['telefono'];
	$nomcont = ucwords($_POST['contacto']);
	$contacto = trim($nomcont);
	$telconta = $_POST['telefonoc'];
	$rh = $_POST['rhsanguineo'];
	$idtipodoc = $_POST['idTipoDoc'];
	$mtransporte = $_POST['medtransporte'];
	$direccion = trim($_POST['direccion']);
	$genero = $_POST['genero'];
	$fingreso = $_POST['fingreso'];
	$computador = trim($_POST['computador']);
	$idemail = $_POST['idemail'];



	$sql = "exec sp_actualizar ?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?";
	$datos = array(
		array($nombre, SQLSRV_PARAM_IN),
		array($documento, SQLSRV_PARAM_IN),
		array($fnacimiento, SQLSRV_PARAM_IN),
		array($ciudadn, SQLSRV_PARAM_IN),
		array($rol, SQLSRV_PARAM_IN),
		array($tel, SQLSRV_PARAM_IN),
		array($contacto, SQLSRV_PARAM_IN),
		array($telconta, SQLSRV_PARAM_IN),
		array($idtipodoc, SQLSRV_PARAM_IN),
		array($ciudadr, SQLSRV_PARAM_IN),
		array($direccion, SQLSRV_PARAM_IN),
		array($rh, SQLSRV_PARAM_IN),
		array($mtransporte, SQLSRV_PARAM_IN),
		array($genero, SQLSRV_PARAM_IN),
		array($fingreso, SQLSRV_PARAM_IN),
		array($computador, SQLSRV_PARAM_IN),
		array($idemail, SQLSRV_PARAM_IN)

	);



	// $exe = $con->query($sql);
	$res = sqlsrv_query($con, $sql, $datos);

	// 		print_r($_POST);
	// print_r(sqlsrv_errors());

	while ($row = sqlsrv_fetch_array($res)) {



		if ($row[0] != 'error') {

			echo "datos actualizados correctamente";
		} else {
			echo "error ,al actualizar,usuario no permitido ó error en algun campo";
		}
	}
}


if ($_POST['btnopcion'] == 'guardaruit') {


	if (!isset($_POST["contrasena"])) {
		echo "la contraseña debe estar habilitada para poder registrar o actualizar!";
	} else {
		# code...
		$usuit = trim($_POST['nameit']);
		$apeit = trim($_POST['lastnameit']);
		$corr = trim($_POST['correouit']);
		$contrasena = trim($_POST['contrasena']);
		$rol=trim($_POST['idrol']);




		$sql = "call ins_user ('$usuit','$apeit','$corr','$contrasena','$rol')";
		




		// $exe = $con->query($sql);
		$exe = $createcon->query($sql);

			// echo gettype($exe);
			// echo $exe;
		// print_r(sqlsrv_errors());

		if ($exe>0 ) {
// echo gettype($exe);

		echo "exito al guardar";
			
		}else{

			echo "error al guardar";

		}
	}
}


if ($_POST['btnopcion'] == 'actualizaruint') {

	if (!isset($_POST["contrasena"])) {
		echo "la contraseña debe estar habilitada para poder registrar o actualizar!";
	} else {

		$idus=trim($_POST['iduint']);
		$usuit = trim($_POST['nameit']);
		$apeit = trim($_POST['lastnameit']);
		$corr = trim($_POST['correouit']);
		$contrasena = trim($_POST['contrasena']);
		$rol=trim($_POST['idrol']);
	




		$sql = "call up_user ('$idus','$usuit','$apeit','$corr','$contrasena','$rol')";
	




		// $exe = $con->query($sql);
		$exe = $createcon->query($sql);

		// 		print_r($_POST);
		// print_r(sqlsrv_errors());
		if ($exe>0 ) {
			// echo gettype($exe);
			
					echo "exito al actualizar";
						
					}else{
			
						echo "error al actualizar";
			
					}
	}
}




if ($_POST['btnopcion'] == 'guardartrbot') {

	if (empty($_POST['ftranbot'])) {
	echo "Necesitamos tener la fecha del registro! ";
	}elseif (empty($_POST['idperstr'])) {
		echo "Necesitamos saber quien hizo este registro!";
	}elseif (empty($_POST['idcliente'])) {
	echo "Necesitamos saber el cliente!";
	}elseif (empty($_POST['idcat'])) {
	echo "necesitamos saber la categoria de transaccion!";
	}elseif (empty($_POST['transl'])) {
		echo "Necesitamos saber por lo menos conocer las transacciones lanzadas!";
	}elseif (empty($_POST['tiahorrado'])) {
	echo "Necesitamos saber cuanto tiempo nos ahorraste!";
	}else {
	
		$ftranbot = trim($_POST['ftranbot']);
	$idperstr = trim($_POST['idperstr']);
	$idcliente = trim($_POST['idcliente']);
	$idcat = trim($_POST['idcat']);
	$transl = trim($_POST['transl']);
	$transexi = trim($_POST['transexi']);
	$tiahorrado = trim($_POST['tiahorrado']);





	$sql = "exec usp_insBotTr ?,?,?,?,?,?,?";
	$datos = array(
		array($ftranbot, SQLSRV_PARAM_IN),
		array($idperstr, SQLSRV_PARAM_IN),
		array($idcliente, SQLSRV_PARAM_IN),
		array($idcat, SQLSRV_PARAM_IN),
		array($transl, SQLSRV_PARAM_IN),
		array($transexi, SQLSRV_PARAM_IN),
		array($tiahorrado, SQLSRV_PARAM_IN),

	);




	// $exe = $con->query($sql);
	$res = sqlsrv_query($con, $sql, $datos);

	// 		print_r($_POST);
	// print_r(sqlsrv_errors());

	while ($row = sqlsrv_fetch_array($res)) {



		if ($row[0] != 'error') {

			echo "transaccion guardada correctamente";
		} else {
			echo "no se permiten campos vacios o registros repetidos entre cliente y categoria";
		}
	}
  }


	
}



if ($_POST['btnopcion'] == 'actualizartrbot') {

	if (empty($_POST['ftranbot'])) {
		echo "Necesitamos tener la fecha del registro! ";
		}elseif (empty($_POST['idperstr'])) {
			echo "Necesitamos saber quien hizo este registro!";
		}elseif (empty($_POST['idcliente'])) {
		echo "Necesitamos saber el cliente!";
		}elseif (empty($_POST['idcat'])) {
		echo "necesitamos saber la categoria de transaccion!";
		}elseif (empty($_POST['transl'])) {
			echo "Necesitamos saber por lo menos conocer las transacciones lanzadas!";
		}elseif (empty($_POST['tiahorrado'])) {
		echo "Necesitamos saber cuanto tiempo nos ahorraste!";
		}else {

	$idtranbot = trim($_POST["idtranbot"]);
	$ftranbot = trim($_POST['ftranbot']);
	$idperstr = trim($_POST['idperstr']);
	$idcliente = trim($_POST['idcliente']);
	$idcat = trim($_POST['idcat']);
	$transl = trim($_POST['transl']);
	$transexi = trim($_POST['transexi']);
	$tiahorrado = trim($_POST['tiahorrado']);





	$sql = "exec usp_updtranbot ?,?,?,?,?,?,?,?";
	$datos = array(
		array($idtranbot, SQLSRV_PARAM_IN),
		array($ftranbot, SQLSRV_PARAM_IN),
		array($idperstr, SQLSRV_PARAM_IN),
		array($idcliente, SQLSRV_PARAM_IN),
		array($idcat, SQLSRV_PARAM_IN),
		array($transl, SQLSRV_PARAM_IN),
		array($transexi, SQLSRV_PARAM_IN),
		array($tiahorrado, SQLSRV_PARAM_IN),

	);




	// $exe = $con->query($sql);
	$res = sqlsrv_query($con, $sql, $datos);

	// 		print_r($_POST);
	// print_r(sqlsrv_errors());

	while ($row = sqlsrv_fetch_array($res)) {



		if ($row[0] != 'error') {

			echo "transaccion guardada correctamente";
		} else {
			echo "no se permiten campos vacios o registros repetidos entre cliente y categoria";
		}
	}
  }
}





if ($_POST['btnopcion'] == 'guardarch') {


	if (empty($_POST['idperso'])) {
		echo "necesitamos saber quien hizo el registro!";
	}elseif (empty($_POST['fechachist'])) {
	echo "necesitamos saber la fecha del reg consu histo";
	}elseif (empty($_POST['idcliente'])) {
		echo "necesitamos saber a que cliente pertenece!";
	}elseif (empty($_POST['cantsusch'])) {
		echo "necesitamos saber la cantidad que registraste !";
	}elseif (empty($_POST['notach'])) {
	 echo "necesitamos que coloques una observacion";
	}else {
		
		$idperso = trim($_POST['idperso']);
	$fechachist = trim($_POST['fechachist']);
	$idcliente = trim($_POST['idcliente']);
	$cantsusch = trim($_POST['cantsusch']);
	$notachi = ucfirst($_POST['notach']);
	$notach = trim($notachi);






	$sql = "exec regchist ?,?,?,?,?";
	$datos = array(
		array($idperso, SQLSRV_PARAM_IN),
		array($fechachist, SQLSRV_PARAM_IN),
		array($idcliente, SQLSRV_PARAM_IN),
		array($cantsusch, SQLSRV_PARAM_IN),
		array($notach, SQLSRV_PARAM_IN),


	);




	// $exe = $con->query($sql);
	$res = sqlsrv_query($con, $sql, $datos);

	// 		print_r($_POST);
	// print_r(sqlsrv_errors());

	while ($row = sqlsrv_fetch_array($res)) {



		if ($row[0] != 'error') {

			echo "transaccion guardada correctamente";
		} else {
			echo "campos vacios ó registro repetido ";
		}
	}
  }

	
}





if ($_POST['btnopcion'] == 'actualizarch') {

	if (empty($_POST['idperso'])) {
		echo "necesitamos saber quien hizo el registro!";
	}elseif (empty($_POST['fechachist'])) {
	echo "necesitamos saber la fecha del reg consu histo";
	}elseif (empty($_POST['idcliente'])) {
		echo "necesitamos saber a que cliente pertenece!";
	}elseif (empty($_POST['cantsusch'])) {
		echo "necesitamos saber la cantidad que registraste !";
	}elseif (empty($_POST['notach'])) {
	 echo "necesitamos que coloques una observacion";
	}else {

	$idconsumo = trim($_POST['idconsumo']);
	$idperso = trim($_POST['idperso']);
	$fechachist = trim($_POST['fechachist']);
	$idcliente = trim($_POST['idcliente']);
	$cantsusch = trim($_POST['cantsusch']);
	$notachi = ucfirst($_POST['notach']);
	$notach = trim($notachi);






	$sql = "exec upchist ?,?,?,?,?,?";
	$datos = array(
		array($idconsumo, SQLSRV_PARAM_IN),
		array($idperso, SQLSRV_PARAM_IN),
		array($fechachist, SQLSRV_PARAM_IN),
		array($idcliente, SQLSRV_PARAM_IN),
		array($cantsusch, SQLSRV_PARAM_IN),
		array($notach, SQLSRV_PARAM_IN),


	);




	// $exe = $con->query($sql);
	$res = sqlsrv_query($con, $sql, $datos);

	// 		print_r($_POST);
	// print_r(sqlsrv_errors());

	while ($row = sqlsrv_fetch_array($res)) {



		if ($row[0] != 'error') {

			echo "transaccion guardada correctamente";
		} else {
			echo "campos vacios, fuera de rango o registro repetido ";
		}
	}
  }
}






if ($_POST['btnopcion'] == 'guardarAnul') {

	if (empty($_POST['fechaanul'])) {
		echo "Se necesita una fecha para el registro!";
	}
	elseif (empty($_POST['idpersanul'])) {
		echo "Necesitamos saber quien hio el registro!";
	} elseif (empty($_POST['idclienteanul'])) {
		echo"Necesitamos saber de que cliente es el error";
		# code...
	}
	elseif (empty($_POST["cantfanul"])) {
		echo "se necesita una cantidad para facturas anuladas";
	}
	elseif(empty($_POST["idmotanul"])) {
		echo "se necesita un motivo de anulacion!";
	} elseif (empty($_POST["autanul"])) {
		echo "está autorizada la anulacion?";
	}elseif (empty($_POST["notaanul"])) {
		echo "se necesita una observacion!";
	}elseif (empty($_POST["errcli"])) {
		echo "se necesita saber si el error llegó al cliente?";
	}elseif (empty($_POST["planacc"])) {
		echo "se necesita un plan de accion";
		# code...
	}else{


		$idpersanul = trim($_POST['idpersanul']);
		$fechaanul = trim($_POST['fechaanul']);
		$idclienteanul = trim($_POST['idclienteanul']);
		$cantfanul = trim($_POST['cantfanul']);
		$idmotanul = trim($_POST['idmotanul']);
		$autanul = trim($_POST['autanul']);
		$notaanul = trim($_POST['notaanul']);
		$errcli = trim($_POST['errcli']);
		$planacc = trim($_POST['planacc']);






		$sql = "exec insAnul ?,?,?,?,?,?,?,?,?";
		$datos = array(
			array($idpersanul, SQLSRV_PARAM_IN),
			array($fechaanul, SQLSRV_PARAM_IN),
			array($idclienteanul, SQLSRV_PARAM_IN),
			array($cantfanul, SQLSRV_PARAM_IN),
			array($idmotanul, SQLSRV_PARAM_IN),
			array($autanul, SQLSRV_PARAM_IN),
			array($notaanul, SQLSRV_PARAM_IN),
			array($errcli, SQLSRV_PARAM_IN),
			array($planacc, SQLSRV_PARAM_IN),


		);




		// $exe = $con->query($sql);
		$res = sqlsrv_query($con, $sql, $datos);

		// 		print_r($_POST);
		// print_r(sqlsrv_errors());

		while ($row = sqlsrv_fetch_array($res)) {



			if ($row[0] != 'error') {
				
				echo "transaccion guardada correctamente";
			} else {
				echo "campos vacios, fuera de rango o registro repetido ";
			}
		}
	}
	
}







if ($_POST['btnopcion'] == 'actualizarAnul') {

	if (empty($_POST['fechaanul'])) {
		echo "Se necesita una fecha para el registro!";
	}
	elseif (empty($_POST['idpersanul'])) {
		echo "Necesitamos saber quien hio el registro!";
	} elseif (empty($_POST['idclienteanul'])) {
		echo"Necesitamos saber de que cliente es el error";
		# code...
	}
	elseif(empty($_POST["idmotanul"])) {
		echo "se necesita un motivo de anulacion!";
	} elseif (empty($_POST["autanul"])) {
		echo "está autorizada la anulacion?";
	}elseif (empty($_POST["notaanul"])) {
		echo "se necesita una observacion!";
	}elseif (empty($_POST["errcli"])) {
		echo "se necesita saber si el error llegó al cliente?";
	}elseif (empty($_POST["planacc"])) {
		echo "se necesita un plan de accion";
		# code...
	}else{

		$idanulacion = trim($_POST['idanulacion']);
		$idpersanul = trim($_POST['idpersanul']);
		$fechaanul = trim($_POST['fechaanul']);
		$idclienteanul = trim($_POST['idclienteanul']);
		$cantfanul = trim($_POST['cantfanul']);
		$idmotanul = trim($_POST['idmotanul']);
		$autanul = trim($_POST['autanul']);
		$notaanul = trim($_POST['notaanul']);
		$errcli = trim($_POST['errcli']);
		$planacc = trim($_POST['planacc']);






		$sql = "exec upAnul ?,?,?,?,?,?,?,?,?,?";
		$datos = array(
			array($idanulacion, SQLSRV_PARAM_IN),
			array($idpersanul, SQLSRV_PARAM_IN),
			array($fechaanul, SQLSRV_PARAM_IN),
			array($idclienteanul, SQLSRV_PARAM_IN),
			array($cantfanul, SQLSRV_PARAM_IN),
			array($idmotanul, SQLSRV_PARAM_IN),
			array($autanul, SQLSRV_PARAM_IN),
			array($notaanul, SQLSRV_PARAM_IN),
			array($errcli, SQLSRV_PARAM_IN),
			array($planacc, SQLSRV_PARAM_IN),


		);




		// $exe = $con->query($sql);
		$res = sqlsrv_query($con, $sql, $datos);

		// 		print_r($_POST);
		// print_r(sqlsrv_errors());

		while ($row = sqlsrv_fetch_array($res)) {



			if ($row[0] != 'error') {

				echo "1";
			} else {
				echo "campos vacios, fuera de rango o registro repetido ";
			}
		}
	}
}



if ($_POST['btnopcion'] == 'guardarcomer') {

	if (!isset($_POST["clavecom"])) {
		echo "la contraseña debe estar habilitada para poder registrar o actualizar!";
	} else {

		$idnomcom = trim($_POST['idnomcom']);
		$servicom = trim($_POST['servicom']);
		$notcom = ucfirst($_POST['notacom']);
		$notacom = trim($notcom);
		$cuentacom = trim($_POST['cuentacom']);
		$clavecom = trim($_POST['clavecom']);
		$linkcom = trim($_POST['linkcom']);
		$correocom = trim($_POST['correocom']);
		$telecom = trim($_POST['telecom']);





		$sql = "exec usp_insertcomer ?,?,?,?,?,?,?,?";
		$datos = array(
			array($idnomcom, SQLSRV_PARAM_IN),
			array($servicom, SQLSRV_PARAM_IN),
			array($notacom, SQLSRV_PARAM_IN),
			array($cuentacom, SQLSRV_PARAM_IN),
			array($clavecom, SQLSRV_PARAM_IN),
			array($linkcom, SQLSRV_PARAM_IN),
			array($correocom, SQLSRV_PARAM_IN),
			array($telecom, SQLSRV_PARAM_IN),


		);




		// $exe = $con->query($sql);
		$res = sqlsrv_query($con, $sql, $datos);

		// 		print_r($_POST);
		// print_r(sqlsrv_errors());

		while ($row = sqlsrv_fetch_array($res)) {



			if ($row[0] != 'error') {

				echo 1;
			} else {
				echo "Error dato repetido , verifique!";
			}
		}
	}
}

if ($_POST['btnopcion'] == 'actualizarcomer') {

	if (!isset($_POST["clavecom"])) {
		echo "la contraseña debe estar habilitada para poder registrar o actualizar!";
	} else {

		$idcomer = trim($_POST['idcomer']);
		$idnomcom = trim($_POST['idnomcom']);
		$servicom = trim($_POST['servicom']);
		$notcom = ucfirst($_POST['notacom']);
		$notacom = trim($notcom);
		$cuentacom = trim($_POST['cuentacom']);
		$clavecom = trim($_POST['clavecom']);
		$linkcom = trim($_POST['linkcom']);
		$correocom = trim($_POST['correocom']);
		$telecom = trim($_POST['telecom']);





		$sql = "exec upd_Comerci ?,?,?,?,?,?,?,?,?";
		$datos = array(
			array($idcomer, SQLSRV_PARAM_IN),
			array($idnomcom, SQLSRV_PARAM_IN),
			array($servicom, SQLSRV_PARAM_IN),
			array($notacom, SQLSRV_PARAM_IN),
			array($cuentacom, SQLSRV_PARAM_IN),
			array($clavecom, SQLSRV_PARAM_IN),
			array($linkcom, SQLSRV_PARAM_IN),
			array($correocom, SQLSRV_PARAM_IN),
			array($telecom, SQLSRV_PARAM_IN),


		);




		// $exe = $con->query($sql);
		$res = sqlsrv_query($con, $sql, $datos);

		// 		print_r($_POST);
		// print_r(sqlsrv_errors());

		while ($row = sqlsrv_fetch_array($res)) {



			if ($row[0] != 'error') {

				echo "transaccion guardada correctamente";
			} else {
				echo "campos vacios, fuera de rango o registro repetido ";
			}
		}
	}
}

if ($_POST['btnopcion'] == 'guardarmg') {


	if (empty($_POST['nommg'])) {
		echo "El registro debe tener un nombre!";
	} elseif (empty($_POST["correomg"]) and empty($_POST["celularmg"]) and empty($_POST["telfimg"])) {
		echo "El registro debe tener por lo menos correo o algun telefono!";
	} else {
		# code...

		# code...


		# code...


		$idclien = trim($_POST['idclien']);
		$nommg = trim($_POST['nommg']);
		$correomg = trim($_POST['correomg']);
		$celularmg = trim($_POST['celularmg']);
		$telfimg = trim($_POST['telfimg']);
		$idreg = trim($_POST['idreg']);
		$respmg = trim($_POST['respmg']);
		$obsmg = ucfirst($_POST['observmg']);
		$observmg = trim($obsmg);




		$sql = "exec ins_Modg ?,?,?,?,?,?,?,?";
		$datos = array(
			array($idclien, SQLSRV_PARAM_IN),
			array($nommg, SQLSRV_PARAM_IN),
			array($correomg, SQLSRV_PARAM_IN),
			array($celularmg, SQLSRV_PARAM_IN),
			array($telfimg, SQLSRV_PARAM_IN),
			array($idreg, SQLSRV_PARAM_IN),
			array($respmg, SQLSRV_PARAM_IN),
			array($observmg, SQLSRV_PARAM_IN),

		);




		// $exe = $con->query($sql);
		$res = sqlsrv_query($con, $sql, $datos);

		// 		print_r($_POST);
		// print_r(sqlsrv_errors());

		while ($row = sqlsrv_fetch_array($res)) {



			if ($row[0] != 'error') {

				echo "transaccion guardada correctamente";
			} else {
				echo "no se permiten campos vacios o registros repetidos entre cliente y categoria";
			}
		}
	}
}


if ($_POST['btnopcion'] == 'actualizarmg') {


	if (empty($_POST['nommg'])) {
		echo "Necesitamos un nombre para el rgistro";
	} elseif (empty($_POST["correomg"]) and empty($_POST["celularmg"]) and empty($_POST["telfimg"])) {
		echo "El registro debe tener por lo menos el correo o algun telefono";
	} else {


			# code...
			$idmogo = trim($_POST['idmogo']);
		$idclien = trim($_POST['idclien']);
		$nommg = trim($_POST['nommg']);
		$correomg = trim($_POST['correomg']);
		$celularmg = trim($_POST['celularmg']);
		$telfimg = trim($_POST['telfimg']);
		$idreg = trim($_POST['idreg']);
		$respmg = trim($_POST['respmg']);
		$obsmg = ucfirst($_POST['observmg']);
		$observmg = trim($obsmg);




		$sql = "exec upd_Mgob ?,?,?,?,?,?,?,?,?";
		$datos = array(
			array($idmogo, SQLSRV_PARAM_IN),
			array($idclien, SQLSRV_PARAM_IN),
			array($nommg, SQLSRV_PARAM_IN),
			array($correomg, SQLSRV_PARAM_IN),
			array($celularmg, SQLSRV_PARAM_IN),
			array($telfimg, SQLSRV_PARAM_IN),
			array($idreg, SQLSRV_PARAM_IN),
			array($respmg, SQLSRV_PARAM_IN),
			array($observmg, SQLSRV_PARAM_IN),

		);




		// $exe = $con->query($sql);
		$res = sqlsrv_query($con, $sql, $datos);

		// 		print_r($_POST);
		// print_r(sqlsrv_errors());

		while ($row = sqlsrv_fetch_array($res)) {



			if ($row[0] != 'error') {

				echo "transaccion guardada correctamente";
			} else {
				echo "no se permiten campos vacios o registros repetidos entre cliente y categoria";
			}
		}

	

		
	}
}



if ($_POST['btnopcion'] == 'insNuComer') {


	if (empty($_POST['nomnucom'])) {
		echo "El campo para nuevo comercializador está vacio";
	}else{


			# code...
		
		$nuComcer = trim($_POST['nomnucom']);
		




		$sql = "exec insNomCom ?";
		$datos = array(
			array($nuComcer, SQLSRV_PARAM_IN),
			

		);




		// $exe = $con->query($sql);
		$res = sqlsrv_query($con, $sql, $datos);

		// 		print_r($_POST);
		// print_r(sqlsrv_errors());

		while ($row = sqlsrv_fetch_array($res)) {



			if ($row[0] != 'error') {

				echo "transaccion guardada correctamente";
			} else {
				echo "Error al guardar comercializador";
			}
		}

	

		
	}
}

if ($_POST['btnopcion'] == 'insNuClien') {


	if (empty($_POST['nueclien'])) {
		echo "El campo para nuevo cliente está vacio";
	}else{


			# code...
		
		$nuClient = trim($_POST['nueclien']);
		




		$sql = "exec insNewCli ?";
		$datos = array(
			array($nuClient, SQLSRV_PARAM_IN),
			

		);




		// $exe = $con->query($sql);
		$res = sqlsrv_query($con, $sql, $datos);

		// 		print_r($_POST);
		// print_r(sqlsrv_errors());

		while ($row = sqlsrv_fetch_array($res)) {



			if ($row[0] != 'error') {

				echo "transaccion guardada correctamente";
			} else {
				echo "Error al guardar cliente,puede ser un registro repetido!";
			}
		}

	

		
	}
}