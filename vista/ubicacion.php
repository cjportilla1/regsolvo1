<?php
error_reporting(0);

session_start();
include("conexion.php");


if (empty($_SESSION["logged"])) {
    header("location:cerrarsesion.php");
}



?>



<!DOCTYPE html>
<meta charset="UTF-8">
<html>


<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible">

    <title>Formulario empleados</title>
    <link rel="stylesheet" href=" ../css/bootstrap.min.css">
    <link rel="stylesheet" href="../css/formulario.css">
    
    <link rel="stylesheet" href="../css/fuente.css">
    <link rel="shortcut icon" href="../assets/img/titleem.ico">
    <script src="https://code.jquery.com/jquery-3.5.1.js"></script>
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

    <script >
        $(document).ready(function(){
            $("#cbx_pais").change(function(){


                    $("#cbx_pais option:selected").each(function(){

                        idpais=$(this).val();
                        $.post("getestado.php",{idpais:idpais},
                        function(data){
                            $("#cbx_estado").html(data);
                        });
                    });
            })
        });

        $(document).ready(function(){
            $("#cbx_estado").change(function(){


                    $("#cbx_estado option:selected").each(function(){

                        idciudad=$(this).val();
                        $.post("getciudad.php",{idciudad:idciudad},
                        function(data){
                            $("#cbx_ciudad").html(data);
                        });
                    });
            })
        });

    </script>
    <script>
    function resetform() {
     $("form select").each(function() { this.selectedIndex = 0 });
     $("form  input[type=text] , form textarea").each(function() { this.value = '' });
     $("form input[type=number]").each(function() { this.value = '' });
     $("form input[type=date]").each(function() { this.value = '' });
     $("form input[type=email]").each(function() { this.value = '' });
     $("form input[type=password]").each(function() { this.value = '' });
     
}
</script>
</head>

<body>


    <div class="wrapper">
        <!-- Sidebar -->
        <nav id="sidebar">
            <div class="sidebar-header border border-success ">
                <img src="../assets/img/Logo.png" alt="" class="w-100 h-100 ">
            </div>

            <ul class="list-unstyled components">
                <p> Módulo interno</p>
            

                <li class="">
                    <a href="#pageSubmenu" data-toggle="collapse" aria-expanded="false" class="dropdown-toggle">Empresas</a>
                    <ul class="collapse list-unstyled" id="pageSubmenu">
                        <li>
                            <a href="intuser.php">Usuarios internos EM</a>
                        </li>
                        <li>
                            <a href="comerc.php">Comercializadores</a>
                        </li>
                        <li>
                            <a href="transbot.php">Transacciones Bot</a>
                        </li>
                        <li>
                            <a href="historicos.php">Registro Consumos Históricos</a>
                        </li>
                        <li>
                            <a href="anulaciones.php">Control de errores</a>
                            
                        </li>
                        <li>
                            <a href="modgob.php">Modelo de gobierno</a>
                            
                        </li>
                    
                    </ul>
                </li>
                <li>
                    <a href="https://energymaster.app/index.php/index " target="_blank" >Energyapp</a>
                </li>
               
                <li class="">
                    <a href="#homeSubmenu" data-toggle="collapse" aria-expanded="false" class="dropdown-toggle">Colaboradores</a>
                    <ul class="collapse list-unstyled" id="homeSubmenu">
                        <li>
                            <a href='formulario.php' disabled>Datos personales colaboradores</a>
                           
                        </li>
                      
                    </ul>
        </nav>


        <div id="content" class=" mx-auto">


            <?php

           if ($_SESSION["perf"] == 'admin') {
               include("ubicacion.inc");
             
            }elseif ($_SESSION["perf"]=='visualizacion') {
                include("forvisual.inc");
            }elseif ($_SESSION["perf"]=='camilo') {
                include("foradmin.inc");
                # code...
            }
            

            ?>



        </div>

    </div>







</body>


</html>