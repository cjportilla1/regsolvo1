'use strict';
function loginUser() {
	// Traemos en una lista los valores del formulario:
	var dataForm = $('#formLogin').serialize();
	// adicionamos el boton concatenando el resultado de serialize con el botón, "&btnlogin=true"
	var datalogin = dataForm + '&btnlogin=true';
	// Comprobar: 	
	//  alert (datalogin);
	//Con ajax controlamos el paso de datos al servicio desde el controlador:
	$.ajax({
		type: "POST",
		url: "controller/login.php",
		data: datalogin,
	}).done(function (res) {
		// Parseo el resultado para volverlo entero:
		this.res = parseInt(res);
		// alert(res);

		// console.log(res);
		if (this.res === 1) {

			// Si al volver entero el resultado es 1, entonces se va a mi página de main:
		
			// console.log(res);
			window.location = "vista/qareg1.php";
		} else {

			// Si no es posible convertirlo en numero, entonces me muestra lo que trae res (respuesta):


			$("#alerta").html(res);



		}
	});
}




//funcion para confirmar la eliminacion de registros
function confirmDelete(id) {
	// preguntamos cn un confirm si desea completar la accion
	var r = confirm("¿Estas seguro de eliminar este registro?");

	if (r == true) {
		// si es cierta la confirmacion  manda sumada en la url por metodo get el id seleccionado para eliminar del registro
		window.location.href = "formulario.php?eliminar&id=" + id;
		setTimeout(recargar, 1500);
	}
}

function confirmDeleteUint(id) {
	// preguntamos cn un confirm si desea completar la accion
	var r = confirm("¿Estas seguro de eliminar este registro?");

	if (r == true) {
		// si es cierta la confirmacion  manda sumada en la url por metodo get el id seleccionado para eliminar del registro
		window.location.href = "intuser.php?eliminar&id=" + id;
		setTimeout(recargar, 1500);
		alert("regresando a la pagina principal");
		// var t =confirm("Se ha eliminado el registro regresando...");
		// if (t=true){
		
		window.location.href="intuser.php";

		// }
	}
}
function confirmDeleteqareg(id) {
	// preguntamos cn un confirm si desea completar la accion
	var r = confirm("¿Estas seguro de eliminar este registro?");

	if (r == true) {
		// si es cierta la confirmacion  manda sumada en la url por metodo get el id seleccionado para eliminar del registro
		window.location.href = "qareg1.php?eliminar&id=" + id;
		setTimeout(recargar, 1500);
		alert("regresando a la pagina principal");
		// var t =confirm("Se ha eliminado el registro regresando...");
		// if (t=true){
		
		window.location.href="qareg1.php";

		// }
	}
}


function confirmDeleteTrBot(id) {
	// preguntamos cn un confirm si desea completar la accion
	var r = confirm("¿Estas seguro de eliminar este registro?");

	if (r == true) {
		// si es cierta la confirmacion  manda sumada en la url por metodo get el id seleccionado para eliminar del registro
		window.location.href = "transbot.php?eliminar&id=" + id;
		setTimeout(recargar, 1500);
	}
}


function confirmDeleteCH(id) {
	// preguntamos cn un confirm si desea completar la accion
	var r = confirm("¿Estas seguro de eliminar este registro?");

	if (r == true) {
		// si es cierta la confirmacion  manda sumada en la url por metodo get el id seleccionado para eliminar del registro
		window.location.href = "historicos.php?eliminar&id=" + id;
		setTimeout(recargar, 1500);
	}
}


function confirmDeleteAnul(id) {
	// preguntamos cn un confirm si desea completar la accion
	var r = confirm("¿Estas seguro de eliminar este registro?");

	if (r == true) {
		// si es cierta la confirmacion  manda sumada en la url por metodo get el id seleccionado para eliminar del registro
		window.location.href = "anulaciones.php?eliminar&id=" + id;
		setTimeout(recargar, 1500);
	}
}

function confirmDeleteComer(id) {
	// preguntamos cn un confirm si desea completar la accion
	var r = confirm("¿Estas seguro de eliminar este registro?");

	if (r == true) {
		// si es cierta la confirmacion  manda sumada en la url por metodo get el id seleccionado para eliminar del registro
		window.location.href = "comerc.php?eliminar&id=" + id;
		setTimeout(recargar, 1500);
	}
}

function confirmDeleteMg(id) {
	// preguntamos cn un confirm si desea completar la accion
	var r = confirm("¿Estas seguro de eliminar este registro?");

	if (r == true) {
		// si es cierta la confirmacion  manda sumada en la url por metodo get el id seleccionado para eliminar del registro
		window.location.href = "modgob.php?eliminar&id=" + id;
		setTimeout(recargar, 1500);
	}
}



function crudcomer(btnSaveUser) {
	// se guarda en una variable los datos que vienen del formulario con id señalizado en la vista del modulo de registro de usuarios
	var datoForm = $("#formComer").serialize();
	// se le suma una variable post btnopcion mas la accion definida en el boton en la vista del formulario ya sea registrar o actualizar
	var datoReg = datoForm + '&btnopcion=' + btnSaveUser;
	// se puede usar un alert para imprimir en pantalla una ventana con los datos que se estan enviando
	//  por post para comprobar que van la cantidad y llenos con los datos correspondientes
	// alert (datoReg);
	console.log();
	// Control asicronico:
	$.ajax({
		type: "POST",
		url: "../controller/registrar.php",
		data: datoReg
	})

		// si la funcion es exitosa y el archivo controlador devuelve una respuesta se registra con el id
		//  del label alerta ubicado en la vista del formulario
		.done(function (res) {
			console.log(res);

			$("#alerta").html(res);
			// se ejecuta la funcion recargar definida mas abajo para actualizar la pagina 
			setTimeout(recargar, 2500);
		})
}





// Función de guardar ó actualizar datos:

function cruduserit(btnSaveUser) {
	// se guarda en una variable los datos que vienen del formulario con id señalizado en la vista del modulo de registro de usuarios
	var datoForm = $("#formRegistroUser").serialize();
	// se le suma una variable post btnopcion mas la accion definida en el boton en la vista del formulario ya sea registrar o actualizar
	var datoReg = datoForm + '&btnopcion=' + btnSaveUser;
	// se puede usar un alert para imprimir en pantalla una ventana con los datos que se estan enviando
	//  por post para comprobar que van la cantidad y llenos con los datos correspondientes
	// alert (datoReg);
	console.log();
	// Control asicronico:
	$.ajax({
		type: "POST",
		url: "../controller/registrar.php",
		data: datoReg
	})

		// si la funcion es exitosa y el archivo controlador devuelve una respuesta se registra con el id
		//  del label alerta ubicado en la vista del formulario
		.done(function (res) {
			console.log(res);

			$("#alerta").html(res);
			// se ejecuta la funcion recargar definida mas abajo para actualizar la pagina 
			setTimeout(recargar, 2500);
		})
}


function createnuclien(btnSaveUser) {
	// se guarda en una variable los datos que vienen del formulario con id señalizado en la vista del modulo de registro de usuarios
	var datoForm = $("#formcliente").serialize();
	// se le suma una variable post btnopcion mas la accion definida en el boton en la vista del formulario ya sea registrar o actualizar
	var datoReg = datoForm + '&btnopcion=' + btnSaveUser;
	// se puede usar un alert para imprimir en pantalla una ventana con los datos que se estan enviando
	//  por post para comprobar que van la cantidad y llenos con los datos correspondientes
	// alert (datoReg);
	console.log();
	// Control asicronico:
	$.ajax({
		type: "POST",
		url: "../controller/registrar.php",
		data: datoReg
	})

		// si la funcion es exitosa y el archivo controlador devuelve una respuesta se registra con el id
		//  del label alerta ubicado en la vista del formulario
		.done(function (res) {
			console.log(res);

			$("#alerta").html(res);
			// se ejecuta la funcion recargar definida mas abajo para actualizar la pagina 
			setTimeout(recargar, 2500);
		})
}







function recargar() {

	location.reload();


}



