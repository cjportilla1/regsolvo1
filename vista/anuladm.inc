<nav class="navbar navbar-expand-lg navbar-light ">

    <div class="container-fluid">

        <button type="button" id="sidebarCollapse" class="btn btn-info">
            <i class="fas fa-align-left"></i>
            <span>Menú</span>
        </button>

    </div>

</nav>
<div class="container col-10 text-center imgs mt-2  formulario1">


    <h1 class="verde titulos ">Control de errores</h1>



    <section class="row justify-content-center p-3">





        <form class="" action="" method="POST" id="formRegistroUser" ectype="multipart/form-data">

        <div class="form-row-12 mb-3">
             <div class="alert alert-danger" role="alert">
  Recuerda: Los campos con  *  son obligatorios!
</div>

             </div>
            <div class="form-row">
                <div class="form-group col-md-4">
                    <label for="inpu"><span class="font-weight-bold">Fecha error *</span></label>
                    <input type="date" value="<?php echo $_POST["fechaanul"]; ?>" class="form-control " id="inputfingreso" name="fechaanul" placeholder="fingreso" <?php echo 'max="' . date('Y-m-d') . '"' ?>>
                </div>

                <div class="form-group col-md-3">
                    <label for="inputca"><span class="font-weight-bold">Gestionado por *</span></label>
                    <select name="idpersanul" id="inputcargo" class="form-control">
                        <option value="" disabled> </option>
                        <?php
                        if (empty($_POST["idpersanul"])) {

                            echo "<option value=''> Seleccione--> ";
                            # code...
                        } else {
                            echo "<option value='" . $_POST["idpersanul"] . "'>" . $_POST["nameanul"] . " ";
                        }
                        ?>
                        <?php
                        $sql = "select * from usuarios order by nombre asc";
                        $res = sqlsrv_query($con, $sql);

                        while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {
                            echo '<option value="' . $row["id"] . '">' . $row["nombre"] . '</option>';
                        }
                        ?>



                    </select>
                </div>


                <div class="form-group col-md-3">
                    <label for="inputca"><span class="font-weight-bold">Cliente *</span></label>
                    <select name="idclienteanul" id="inputcargo" class="form-control">
                    <option value="" disabled> </option>
                        <?php
                        if (empty($_POST["idclienteanul"])) {

                            echo "<option value=''> Seleccione--> ";
                            # code...
                        } else {
                            echo "<option value='" . $_POST["idclienteanul"] . "'>" . $_POST["clienteanul"] . " ";
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
                <div class="form-group col-sm-2 my-auto">

<button type="button" class="btn btn-verde text-light titulos " data-toggle="modal" data-target="#exampleModal">
    Nuevo cliente
</button>
</div>


            </div>
            <div class="form-row">

                <div class="form-group col-md-4">
                    <label for="inputca"><span class="font-weight-bold">Motivo error *</span></label>
                    <select name="idmotanul" id="inputcargo" class="form-control">
                    <option value="" disabled> </option>
                        <?php
                        if (empty($_POST["idmotanul"])) {

                            echo "<option value=''> Seleccione--> ";
                            # code...
                        } else {
                            echo "<option value='" . $_POST["idmotanul"] . "'>" . $_POST["descrmotanul"] . " ";
                        }
                        ?>
                        <?php
                        $sql = "SELECT * from Mot_anula";
                        $res = sqlsrv_query($con, $sql);

                        while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {
                            echo '<option value="' . $row["idMotanul"] . '">' . $row["descrAnul"] . '</option>';
                        }
                        ?>




                    </select>
                </div>

                <div class="form-group col-md-4">
                    <label for="inputtel"><span class="font-weight-bold">Cant fac errores *</span></label>
                    <input name="cantfanul" type="number" value="<?php echo $_POST["cantfanul"]; ?>" class="form-control" id="inputTel" placeholder="Cantidad Fac errores" min="1" max="100">
                </div>

                <div class="form-group col-md-4">
                    <label for="inputca"><span class="font-weight-bold">Autorizado? *</span></label>
                    <select name="autanul" id="inputcargo" class="form-control">

                    <option value="" disabled> </option>
                        <?php
                        if (empty($_POST["autanul"])) {

                            echo "<option value=''> Seleccione--> ";
                            # code...
                        } else {
                            echo "<option value='" . $_POST["autanul"] . "'>" . $_POST["autanul"] . " ";
                        }
                        ?>
                        <option value="Si">Si</option>
                        <option value="No">No</option>

                    </select>

                </div>

















            </div>

            <div class="form-row">
                <label for="inputtel"><span class="font-weight-bold">Detalle error *</span></label>
                <textarea name="notaanul" type="text" class="form-control" id="inputTel" placeholder="Descripcion del error"><?php echo $_POST["notaanul"]; ?></textarea>


            </div>

            <div class="form-row mb-2">
                <div class="col">

                    <label for="inputca"><span class="font-weight-bold">Error llegó al cliente? *</span></label>
                    <select name="errcli" id="iderrcli" class="form-control">
                    <option value="" disabled> </option>
                        <?php
                        if (empty($_POST["errcli"])) {

                            echo "<option value=''> Seleccione--> ";
                            # code...
                        } else {
                            echo "<option value='" . $_POST["errcli"] . "'>" . $_POST["errcli"] . " ";
                        }
                          


 
                        ?>
                        <option value="Si">Si</option>
                        <option value="No">No</option>

                    </select>



                    <label for="inputtel"><span class="font-weight-bold">Plan de acción *</span></label>
                    <textarea name="planacc" type="text" class="form-control" id="idplanacc" placeholder="Plan de accion"><?php echo $_POST["planacc"]; ?></textarea>

                </div>


            </div>
         






            <div class="form-row ">


                <div class="col-4">

                    <button type="button" onclick="cruduser('guardarAnul')" class="btn btn-verde text-light titulos">
                        REGISTRAR </button> <br>
                    <br>



                </div>

                <div class="col-4">
                <button type="button" onclick="resetform()" class="btn btn-verde text-light titulos" id="btnform">
                       Limpiar formulario </button> <br>

                </div>
 
                <div class="col-4">

                    <button type="button" onclick="cruduser('actualizarAnul')" class="btn btn-verde text-light titulos" id="btnform">
                        ACTUALIZAR </button> <br>
                    
                    <article id="alerta" class="alert-warning text-danger"></article>

                </div>




            </div>

            <div class="form-row-12">
                <mark> <a href="cerrarsesion.php" class="text-danger btn btn-warning">Cerrar sesion</a> </mark>
                <?php

                if (empty($_POST["idanulacion"])) {
                    echo '<input type="hidden" name="idanulacion" value="0">';

                    # code...
                } elseif (!empty($_POST["idanulacion"])) {
                    echo '<input type="hidden" name="idanulacion" value="' . $_POST["idanulacion"] . '">';
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
                            <h3 class="modal-title verde titulos " id="exampleModalLabel">Registrar nuevo cliente</h3>
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
        <table id="tusuarios" class=" table-striped " width="100%" height="100%">
            <thead class=" ">
                <tr class=" text-center fverde   text-light">
                    <th>Eliminar</th>
                    <th>Editar</th>
                    <th>Fecha anulación</th>
                    <th>Realizado por</th>
                    <th>Cliente</th>
                    <th>Cant fac anuladas</th>
                    <th>Motivo anulación</th>
                    <th>Error llegó al cliente?</th>
                    <th>Plan de accion:</th>
                    <th>Autorizada?</th>
                    <th>Detalle error</th>







                </tr>
            </thead>
            <tbody>


                <?php

                if (isset($_GET['eliminar'])) {

                    $sqlDelete = "delete from Anulacion where idAnulacion=?";
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
               select idAnulacion,idusrAn,U.nombre,feAnul,idClienteA,C.nomCliente,cantFanul,M.idMotanul,M.descrAnul,anulAut,NotaAn,cliErr,planAcc from Anulacion A 
               inner join usuarios U on idusrAn=id
               inner join Cliente C on idClienteA=c.idCliente
               inner join Mot_anula M on A.idMotanul=M.idMotanul
               order by idAnulacion desc";


                $res = sqlsrv_query($con, $sql);




                while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {

                    switch ($row["idClienteA"]) {
                        case '1':
                            $cliente = "<IMG src='../assets/img/d1icon.ico' width='70%' height='30%'  >";
                            break;

                        case '2':
                            $cliente = "<IMG src='../assets/img/bbogota.ico' width='70%' height='30%'   >";
                            break;

                        case '3':
                            $cliente = "<IMG src='../assets/img/distracom.ico' width='70%' height='30%'     >";
                            break;

                        case '4':
                            $cliente = "<IMG src='../assets/img/velez.ico' width='70%' height='30%'    >";
                            break;

                        case '5':
                            $cliente = "<IMG src='../assets/img/studiof.ico' width='70%' height='30%'    >";
                            break;

                            case '7':
                                $cliente = "<IMG src='../assets/img/colanta.ico' width='70%' height='30%'      >";
                                break;

                            case '8':
                                $cliente = "<IMG src='../assets/img/larebaja.ico' width='70%' height='30%'      >";
                                break;

                                case '9':
                                    $cliente = "GRUPO URIBE";
                                    break;

                                    case '10':
                                        $cliente = "<IMG src='../assets/img/hermeco.ico' width='70%' height='30%'      >";
                                        break;
                                   
                        case '11':
                            $cliente = "<IMG src='../assets/img/leonisa.ico' width='70%' height='30%'      >";
                            break;

                            case '12':
                                $cliente = "<IMG src='../assets/img/tcc.ico' width='70%' height='30%'      >";
                                break;


                                case '13':
                                    $cliente = "<IMG src='../assets/img/diag.ico' width='70%' height='30%'  >";
                                    break;
                         
                                    case '14':
                                        $cliente="<IMG src='../assets/img/bbva.ico' width='70%' height='30%'      >";
                                    break;
        
                                    case '15':
                                        $cliente="<IMG src='../assets/img/av villas.ico' width='70%' height='30%'      >";
                                    break;
        
                                    case '16':
                                        $cliente="<IMG src='../assets/img/popular.ico' width='70%' height='30%'      >";
                                    break;
        
                                    case '17':
                                        $cliente="<IMG src='../assets/img/boccidente.ico' width='70%' height='30%'      >";
                                    break;
                                    
                                    case '18':
                                        $cliente="<IMG src='../assets/img/porvenir.ico' width='70%' height='30%'      >";
                                    break;
                                    case '19':
                                        $cliente="<IMG src='../assets/img/pilatos.ico' width='70%' height='30%'      >";
                                    break;

                    }

                    if ($row["cliErr"]=='Si') {
                        $errcli="<h3 class='text-danger'>".$row["cliErr"]."</h3>";
                        # code...
                    }else {
                        $errcli="<h3 class='text-dark'>".$row["cliErr"]."</h3>";
                    }



                    echo "<tr class='text-center textop ' >
                   <td>  <a href='#' class='btn btn-rojo  fenergy' onclick='confirmDeleteAnul(" . $row["idAnulacion"] . ");'>Eliminar</button></td>
                   <td>
                   <form action='' method='POST'>

               <input type='hidden' name='idanulacion' value='" . $row["idAnulacion"] . "'>
  
                  <input type='hidden' name='idpersanul' value='" . $row["idusrAn"] . "'>
                  <input type='hidden' name='nameanul' value='" . $row["nombre"] . "'>
                  <input type='hidden' name='fechaanul' value='" . $row["feAnul"]->format('Y-m-d')  . "'>
                  <input type='hidden' name='idclienteanul' value='" . $row["idClienteA"] . "'>
                  <input type='hidden' name='clienteanul' value='" . $row["nomCliente"] . "'>
                  <input type='hidden' name='cantfanul' value='" . $row["cantFanul"] . "'>
                  <input type='hidden' name='idmotanul' value='" . $row["idMotanul"] . "'>
                  <input type='hidden' name='descrmotanul' value='" . $row["descrAnul"] . "'>
                  <input type='hidden' name='autanul' value='" . $row["anulAut"] . "'>
                  <input type='hidden' name='notaanul' value='" . $row["NotaAn"] . "'>
                  <input type='hidden' name='errcli' value='" . $row["cliErr"] . "'>
                  <input type='hidden' name='planacc' value='" . $row["planAcc"] . "'>
                  <input class='btn btn-verde  fenergy' type='submit'  value='Editar/act' name='accion'>
                  </form>
               
                  </td>
                  
                
                       <td><h6>" . $row["feAnul"]->format('Y-m-d') . "</h6></td>
                       <td>" . $row["nombre"] . "</td>
                         <td>" . $cliente ."<p style='visibility:hidden'>".$row["nomCliente"]. "</p></td>
                       <td><h6 class='font-weight-bold '>" . $row["cantFanul"] . "</h6></td>
                       <td>" . $row["descrAnul"] . "</td>
                       <td>" . $errcli . "</td>
                       <td>" . $row["planAcc"] . "</td>
                       <td>" . $row["anulAut"] . "</td>
                       <td>" . $row["NotaAn"] . "</td>
                       
                    
                       </tr>";
                }




                ?>

    </div>


    </tbody>


    </table>
</div>