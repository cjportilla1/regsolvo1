<nav class="navbar navbar-expand-lg navbar-light ">

<div class="container-fluid">

    <button type="button" id="sidebarCollapse" class="btn btn-info">
        <i class="fas fa-align-left"></i>
        <span>Menú</span>
    </button>

</div>

</nav>


<div class="container col-10 text-center imgs mt-2  formulario1">


    <h1 class="verde titulos ">Registros Consumos Historicos</h1>



    <section class="row justify-content-center p-4">





        <form class="" action="" method="POST" id="formRegistroUser" ectype="multipart/form-data">


            <div class="form-row">
                <div class="form-group col-md-6">
                    <label for="inpu"><span class="font-weight-bold">Fecha de entrega consumos historicos *</span></label>
                    <input type="date" value="<?php echo $_POST["fechachist"]; ?>" class="form-control " id="inputfingreso" name="fechachist" placeholder="fingreso" <?php echo 'max="' . date('Y-m-d') . '"' ?>>
                </div>

                <div class="form-group col-md-6">
                    <label for="inputca"><span class="font-weight-bold">Historico gestionado por *</span></label>
                    <select name="idperso" id="inputwho" class="form-control">
                    <option value="" disabled> </option>
                        <?php
                        if (empty($_POST["idperso"])) {

                            echo "<option value=''> seleccione--> ";
                            # code...
                        } else {
                            echo "<option value='" . $_POST["idperso"] . "'>" . $_POST["namech"] . " ";
                        }
                        ?>
                        <?php
                        $sql = "SELECT * from usuarios order by nombre";
                        $res = sqlsrv_query($con, $sql);

                        while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {
                            echo '<option value="' . $row["id"] . '">' . $row["nombre"] . '</option>';
                        }
                        ?>



                    </select>
                </div>




            </div>
            <div class="form-row">



                <div class="form-group col-sm-5">
                    <label for="inputtel"><span class="font-weight-bold">Cantidad suscripciones Cons Hist *</span></label>
                    <input name="cantsusch" type="number" value="<?php echo $_POST["cantsusch"]; ?>" class="form-control" id="inputTel" placeholder="#cantidad de suscripciones" min="1" max="100">
                </div>



                <div class="form-group col-sm-4">
                    <label for="inputca"><span class="font-weight-bold">Cliente *</span></label>
                    <select name="idcliente" id="inputclient" class="form-control">
                    <option value="" disabled> </option>
                        <?php
                        if (empty($_POST["idcliente"])) {

                            echo "<option value=''> seleccione--> ";
                            # code...
                        } else {
                            echo "<option value='" . $_POST["idcliente"] . "'>" . $_POST["nomcliente"] . " ";
                        }
                        ?>

                        <?php
                        $sql = "select * from Cliente order by nomCliente asc";
                        $res = sqlsrv_query($con, $sql);

                        while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {
                            echo '<option value="' . $row["idCliente"] . '">' . $row["nomCliente"] . '</option>';
                        }
                        ?>




                    </select>
                </div>

                <div class="form-group col-sm-3 my-auto">

                    <button type="button" class="btn btn-verde text-light titulos " data-toggle="modal" data-target="#exampleModal">
                        Nuevo cliente
                    </button>
                </div>



            </div>


           


<div class="form-row-12">
    <label for="inputtel"><span class="font-weight-bold fenergy">Observacion *</span></label>
    <textarea name="notach" type="text" class="form-control mb-2" id="inputTel" placeholder="observaciones"><?php echo $_POST["notach"]; ?></textarea>
</div>

<div class="form-row-12 mb-3">
             <div class="alert alert-danger" role="alert">
  Recuerda: Los campos con  *  son obligatorios!
</div>

             </div>

<div class="form-row">



    <div class="col-2"> </div>
    <div class="col">
  

        <button type="button" onclick="cruduser('guardarch')" class="btn btn-verde text-light titulos">
            REGISTRAR </button> <br>
        <br>

    </div>
    <div class="col">
     <button type="button" onclick="resetform()" class="btn btn-verde text-light titulos btn-sm" id="btnform">
                       Limpiar formulario </button> <br>

                </div>
    <div class="col">

        <button type="button" onclick="cruduser('actualizarch')" class="btn btn-verde text-light titulos">
            ACTUALIZAR </button> <br>

        <article id="alerta" class="alert-warning text-danger"></article>

    </div>


    <div class="col-2"> </div>

</div>


<div class="form-row-12">
    <mark> <a href="cerrarsesion.php" class="text-danger btn btn-warning">Cerrar sesion</a> </mark>
    <?php

    if (empty($_POST["idconsumo"])) {
        echo '<input type="hidden" name="idconsumo" value="0">';

        # code...
    } elseif (!empty($_POST["idconsumo"])) {
        echo '<input type="hidden" name="idconsumo" value="' . $_POST["idconsumo"] . '">';
        # code...
    }
    ?>

    <!-- <?php print_r($_SESSION); ?> -->
</div>


</form>



</section>




</div>

 <!-- Modal -->
 <div class="modal fade" id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
                <div class="modal-dialog" role="document">
                    <div class="modal-content">
                        <div class="modal-header">
                            <h3 class="modal-title verde titulos" id="exampleModalLabel">Registrar nuevo cliente</h3>
                            <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                                <span aria-hidden="true">&times;</span>
                            </button>
                        </div>
                        <div class="modal-body">


                            <div class="row  ">
                                <div class="form-group col-md-4 text-center">
                                    <form action="" method="POST" id="formcliente">
                                        <label for="inputsd"><span class="font-weight-bold fenergy">Nuevo cliente</span></label>
                                </div>

                                <div class="form-group col-md-8 text-center">

                                    <input name="nueclien" type="text" class="form-control " id="newclient" placeholder="Nombre nuevo cliente" minlength="3" maxlength="60" value="">
                                </div>


                            </div>


                        </div>
                        <div class="modal-footer">
                            <button type="button" class="btn btn-gris btn-sm" data-dismiss="modal">Cerrar</button>
                            <button type="button" onclick="createnuclien('insNuClien')" class="btn btn-verde btn-sm text-light titulos ">Registrar</button>
                             
                        </div>
                        </form>
                    </div>
                </div>
            </div>

            <!-- fin del modal  esta parte no es visible en el front end hasa que se presione el boton que lo activa -->

<div class="container mt-5 col-12 ">
    <div class="container formulario1 imgs p-4">
        <table id="tusuarios" class="  table-striped " width="100%" height="100%">
            <thead class=" ">
                <tr class=" text-center fverde   text-light">
                    <th>Eliminar</th>
                    <th>Editar</th>
                    <th>Gestionado por</th>
                    <th>Fecha ingreso consumos his</th>
                    <th>Cliente</th>
                    <th>Cantidad suscripciones Cons Hist</th>
                    <th>Observacion</th>








                </tr>
            </thead>
            <tbody>


                <?php

                if (isset($_GET['eliminar'])) {

                    $sqlDelete = "delete from Chistorico where idConsumo=?";
                    $datos = array(
                        array($_GET['id'], SQLSRV_PARAM_IN),
                    );
                    $resu = sqlsrv_query($con, $sqlDelete, $datos);


                    while ($row = sqlsrv_fetch_array($resu)) {


                        if ($row[0] != 'error') {
                            echo "<label class='text-danger' >usuario eliminado correctamente</label>";
                        } else {
                            echo "<label class='text-danger' >usuario admin,no se puede eliminar</label>";
                        }
                    }
                }


                $sql = "	
                    select ch.idConsumo,ch.idPerso,nombre,ch.fechaChist,ch.idCliente,c.nomCliente,ch.canSusch,ch.obsCh from Chistorico ch
inner join usuarios  on ch.idPerso=id
inner join  Cliente c on ch.idCliente=c.idCliente
order by idConsumo desc";


                $res = sqlsrv_query($con, $sql);




                while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {


                    switch ($row["idCliente"]) {
                        case '1':
                            $cliente = "<IMG src='../assets/img/d1icon.ico' width='70%' height='30%'    >";
                            break;

                        case '2':
                            $cliente = "<IMG src='../assets/img/bbogota.ico' width='70%' height='30%'    >";
                            break;

                        case '3':
                            $cliente = "<IMG src='../assets/img/distracom.ico' width='70%' height='30%'      >";
                            break;

                        case '4':
                            $cliente = "<IMG src='../assets/img/velez.ico' width='70%' height='30%'    >";
                            break;

                        case '5':
                            $cliente = "<IMG src='../assets/img/studiof.ico' width='70%' height='30%'      >";
                            break;

                        case '7':
                            $cliente = "<IMG src='../assets/img/colanta.ico' width='70%' height='30%'     >";
                            break;

                        case '8':
                            $cliente = "<IMG src='../assets/img/larebaja.ico' width='70%' height='30%'      >";
                            break;

                        case '9':
                            $cliente = "GRUPO URIBE";
                            break;

                        case '10':
                            $cliente = "<IMG src='../assets/img/hermeco.ico' width='70%' height='30%'     >";
                            break;

                        case '11':
                            $cliente = "<IMG src='../assets/img/leonisa.ico' width='70%' height='30%'     >";
                            break;

                        case '12':
                            $cliente = "<IMG src='../assets/img/tcc.ico' width='70%' height='30%'     >";
                            break;


                        case '13':
                            $cliente = "<IMG src='../assets/img/diag.ico' width='70%' height='30%'      >";
                            break;

                            case '14':
                                $cliente="<IMG src='../assets/img/bbva.ico' width='70%' height='30%'    >";
                            break;

                            case '15':
                                $cliente="<IMG src='../assets/img/av villas.ico' width='70%' height='30%'    >";
                            break;

                            case '16':
                                $cliente="<IMG src='../assets/img/popular.ico' width='70%' height='30%'      >";
                            break;

                            case '17':
                                $cliente="<IMG src='../assets/img/boccidente.ico' width='70%' height='30%'     >";
                            break;
                            
                            case '18':
                                $cliente="<IMG src='../assets/img/porvenir.ico' width='70%' height='30%'      >";
                            break;
                            case '19':
                                        $cliente="<IMG src='../assets/img/pilatos.ico' width='70%' height='30%'      >";
                                    break;

                    }

                    echo "<tr class='text-center texto ' >
                        <td>  <a href='#' class='btn btn-rojo fenergy ' onclick='confirmDeleteCH(" . $row["idConsumo"] . ");'>Eliminar</button></td>
                        <td>
                        <form action='' method='POST'>

                      <input type='hidden' name='idconsumo' value='" . $row["idConsumo"] . "'>
                         <input type='hidden' name='namech' value='" . $row["nombre"] . "'>
                       <input type='hidden' name='idperso' value='" . $row["idPerso"] . "'>
                       <input type='hidden' name='fechachist' value='" . $row["fechaChist"]->format('Y-m-d')  . "'>
                       <input type='hidden' name='idcliente' value='" . $row["idCliente"] . "'>
                       <input type='hidden' name='nomcliente' value='" . $row["nomCliente"] . "'>
                       <input type='hidden' name='cantsusch' value='" . $row["canSusch"] . "'>
                       <input type='hidden' name='notach' value='" . $row["obsCh"] . "'>
                      
                       <input class='btn btn-verde fenergy ' type='submit'  value='Editar/act' name='accion'>
                       </form>
                    
                       </td>
                       
                     
                        
                            <td>" . $row["nombre"] . "</td>
                            <td>" . $row["fechaChist"]->format('Y-m-d') . "</td>
                   <td>" . $cliente . "<p style='visibility:hidden'>" . $row["nomCliente"] . "</p></td>
                            <td>" . $row["canSusch"] . "</td>
                            <td>" . $row["obsCh"] . "</td>
                           
                           
                    
                           
                         
                            
                         
                            </tr>";
                }




                ?>

    </div>


    </tbody>


    </table>
</div>