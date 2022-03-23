<?php
error_reporting(0);

session_start();


include("conexion.php");


$con = New Conexion();
$createcon=$con->conectar();
$createcon->set_charset("utf8");


// print_r($_SESSION);
// print_r($_POST);


if (empty($_SESSION["logged"])){
    header("location:cerrarsesion.php");
}
date_default_timezone_set('Etc/GMT-5');

?>



<!DOCTYPE html>
<meta charset="UTF-8">
<html>


<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta http-equiv="X-UA-Compatible">

    <title>Usuarios internos empresas</title>
    
    <link rel="stylesheet" href=" ../css/bootstrap.min.css">
    <link rel="stylesheet" href="../css/formulario.css">
    
    <link rel="stylesheet" href="../css/fuente.css">
    <link rel="shortcut icon" href="../assets/img/solvoico.ico">
    <link rel="stylesheet" href="../assets/fontawesome-free-5.15.1-web/css/all.css">
   
    
    <!-- <script src="https://code.jquery.com/jquery-3.5.1.js"></script> -->
    <script type="text/javascript" src="../js/jquery-3.5.1.min.js"></script>
    <link rel="stylesheet" type="text/css" href="../assets/DataTables-1.10.22/css/jquery.dataTables.css"/>
<link rel="stylesheet" type="text/css" href="../assets/Buttons-1.6.4/css/buttons.dataTables.css"/>
<link rel="stylesheet" type="text/css" href="../assets/Responsive-2.2.6/css/responsive.dataTables.css"/>
 
<script type="text/javascript" src="../assets/JSZip-2.5.0/jszip.js"></script>
<script type="text/javascript" src="../assets/pdfmake-0.1.36/pdfmake.js"></script>
<script type="text/javascript" src="../assets/pdfmake-0.1.36/vfs_fonts.js"></script>
<script type="text/javascript" src="../assets/DataTables-1.10.22/js/jquery.dataTables.js"></script>
<script type="text/javascript" src="../assets/Buttons-1.6.4/js/dataTables.buttons.js"></script>
<script type="text/javascript" src="../assets/Buttons-1.6.4/js/buttons.colVis.js"></script>
<script type="text/javascript" src="../assets/Buttons-1.6.4/js/buttons.flash.js"></script>
<script type="text/javascript" src="../assets/Buttons-1.6.4/js/buttons.html5.js"></script>
<script type="text/javascript" src="../assets/Buttons-1.6.4/js/buttons.print.js"></script>
<script type="text/javascript" src="../assets/Responsive-2.2.6/js/dataTables.responsive.js"></script>




    
    <script type="text/javascript" src="../js/bootstrap.js"></script>
    <script type="text/javascript" src="../js/popper.js"></script>

   
    <script type="text/javascript" src="../js/funciones.js"></script>
    
  
  

   

    <script>
  function mostrarContrasena(){
      var tipo = document.getElementById("inputpass");
      if(tipo.type == "password"){
          tipo.type = "text";
      }else{
          tipo.type = "password";
      }
  }
</script>

<!-- script para habilitar el campo de contraseña -->
<script>
function habilCont(campoCantidad)
{
	var estadoActual = document.getElementById(campoCantidad)

	if(estadoActual.disabled == true)
	{
		estadoActual.disabled=false;
	}
	else
	{
		estadoActual.disabled=true;
	}
}
</script>



    <script type="text/javascript">
        $(document).ready(function() {

            $('#sidebarCollapse').on('click', function() {
                $('#sidebar').toggleClass('active');
            });

        });
    </script>


<script>
        $(document).ready(function() {
    $('#tusuarios').DataTable( {
        dom: 'Bfrtip',

        scrollY:        "700px",
        scrollX:        true,
        scrollCollapse: true,
        paging:         true,
      
        lengthMenu: [
            [ 10, 25, 50, -1 ],
            [ '10 filas', '25 filas', '50 filas', 'mostrar todo' ]
        ],
       
        buttons: [
            'pageLength',
            {
                extend: 'copyHtml5',
                exportOptions: {
                    columns: [ 0, ':visible' ]
                }
            },
            {
                extend: 'excelHtml5',
                exportOptions: {
                    columns: ':visible'
                }

            },
            {
                extend: 'pdfHtml5',
                exportOptions: {
                    
                    
                    columns: ':visible',
                    orientation: 'landscape',
                   pageSize: 'LEGAL',
                  
               
                modifier: {
                    page: 'current',
                   
                }
                },
              
                
            },'colvis'
            
        ]
        

        
    } );
} );
    </script>

<script>
    function resetform() {
     $("form select").each(function() { this.selectedIndex = 0 });
     $("form  input[type=text] , form textarea").each(function() { this.value = '' });
     $("form input[type=number]").each(function() { this.value = '' });
     $("form input[type=date]").each(function() { this.value = '' });
     $("form input[type=email]").each(function() { this.value = '' });
     $("form input[type=password]").each(function() { this.value = '' });
    //  $_POST=array();
}
</script>

</head>

<body>


    <div class="wrapper">
        <!-- Sidebar -->
        <nav id="sidebar">
            <?php include("menu.inc")  ?>
           
        </nav>


        <div id="content" class="cuerpo mx-auto">
            <nav class="navbar navbar-expand-lg navbar-light ">

                <div class="container-fluid">

                    <button type="button" id="sidebarCollapse" class="btn btn-info">
                        <i class="fas fa-align-left"></i>
                        <span>Menú</span>
                    </button>

                </div>

            </nav>
           
            <?php     
                if ($_SESSION["perf"]=='admin') {
                    include("userintadm.inc");

                    # code...
                }elseif ($_SESSION["perf"]=='supervisor') {
                    include("intuservisual.inc");
                    # code...
                }elseif ($_SESSION["perf"]=='colaborador') {
                    include("intuservisual.inc");
                    # code...
                }

            ?>

        </div>

    </div>







</body>


</html>