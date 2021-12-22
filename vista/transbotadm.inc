

 <div class="container col-10 text-center imgs mt-2  formulario1">


     <h1 class="verde titulos ">Registro transacciones del robot</h1>



     <section class="row justify-content-center p-2">





         <form class="" action="" method="POST" id="formRegistroUser" ectype="multipart/form-data">


             <div class="form-row">
                 <div class="form-group col-md-4">
                     <label for="inpu"><span class="font-weight-bold">Fecha automatización *</span></label>
                     <input type="date" value="<?php echo $_POST["ftranbot"]; ?>" class="form-control " id="inputfingreso" name="ftranbot" placeholder="fingreso" <?php echo 'max="' . date('Y-m-d') . '"' ?>>
                 </div>

                 <div class="form-group col-md-3">
                     <label for="inputca"><span class="font-weight-bold">Gestionado por *</span></label>
                     <select name="idperstr" id="inputcargo" class="form-control">
                     <option value="" disabled> </option>
                         <?php
                            if (empty($_POST["idperstr"])) {

                                echo "<option value=''> Seleccione--> ";
                                # code...
                            } else {
                                echo "<option value='" . $_POST["idperstr"] . "'>" . $_POST["name"] . " ";
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
                     <select name="idcliente" id="inputcargo" class="form-control">
                     <option value="" disabled> </option>
                         <?php
                            if (empty($_POST["idcliente"])) {

                                echo "<option value=''> Seleccione--> ";
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

                 <div class="form-group col-sm-2 my-auto">

                    <button type="button" class="btn btn-verde text-light titulos " data-toggle="modal" data-target="#exampleModal">
                        Nuevo cliente
                    </button>
                </div>



             </div>
             <div class="form-row">

                 <div class="form-group col-md-4">
                     <label for="inputca"><span class="font-weight-bold">Categoría transacción *</span></label>
                     <select name="idcat" id="inputcargo" class="form-control">
                     <option value="" disabled> </option>
                         <?php
                            if (empty($_POST["idcat"])) {

                                echo "<option value=''> Seleccione--> ";
                                # code...
                            } else {
                                echo "<option value='" . $_POST["idcat"] . "'>" . $_POST["descat"] . " ";
                            }
                            ?>
                         <?php
                            $sql = "SELECT * from Cat_Transaccion order by desCat";
                            $res = sqlsrv_query($con, $sql);

                            while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {
                                echo '<option value="' . $row["idcattr"] . '">' . $row["desCat"] . '</option>';
                            }
                            ?>




                     </select>
                 </div>

                 <div class="form-group col-md-4">
                     <label for="inputtel"><span class="font-weight-bold">Transacciones lanzadas *</span></label>
                     <input name="transl" type="number" value="<?php echo $_POST["transl"]; ?>" class="form-control" id="inputTel" placeholder="#transacciones lanzadas" min="1" max="100">
                 </div>

                 <div class="form-group col-md-4">
                     <label for="inputtel"><span class="font-weight-bold">Transacciones exitosas</span></label>
                     <input name="transexi" type="number" value="<?php echo $_POST["transexi"]; ?>" class="form-control" id="inputTel" placeholder="#transacciones exitosas" min="1" <?php if (empty($_POST["transl"])) {
                                                                                                                                                                                            echo ' max="20"';
                                                                                                                                                                                            # code...
                                                                                                                                                                                        } elseif (!empty($_POST["transl"])) {

                                                                                                                                                                                            echo ' max="' . $_POST["transl"] . '"';
                                                                                                                                                                                        }

                                                                                                                                                                                        ?>>
                 </div>











             </div>


             <div class="form-row">

                 <div class="col-4"></div>
                 <div class="form-group col-4">
                     <label for="inputtel"><span class="font-weight-bold">Tiempo ahorrado *</span></label>
                     <input name="tiahorrado" type="number" value="<?php echo $_POST["tiahorrado"]; ?>" class="form-control" id="inputTel" placeholder="#tiempo ahorrado en horas" min="1" max="8" step="any">



                     </select>

                 </div>
                 <div class="col-4"></div>
             </div>
             <div class="form-row-12 mb-3">
             <div class="alert alert-danger" role="alert">
  Recuerda: Los campos con  *  son obligatorios!
</div>

             </div>




             <div class="form-row">

                 <div class="col-2"></div>
                 <div class="col">

                     <button type="button" onclick="cruduser('guardartrbot')" class="btn btn-verde text-light titulos">
                         REGISTRAR </button> <br>
                     <br>



                 </div>
                 <div class="col">
                <button type="button" onclick="resetform()" class="btn btn-verde text-light titulos" id="btnform">
                       Limpiar formulario </button> <br>

                </div>
                 <div class="col">

                     <button type="button" onclick="cruduser('actualizartrbot')" class="btn btn-verde text-light titulos">
                         ACTUALIZAR </button> <br>

                     <article id="alerta" class="alert-warning text-danger"></article>

                 </div>

                 <div class="col-2"></div>


             </div>

             <div class="form-row-12">
                 <mark> <a href="cerrarsesion.php" class="text-danger btn btn-warning">Cerrar sesión</a> </mark>
                 <?php

                    if (empty($_POST["idtranbot"])) {
                        echo '<input type="hidden" name="idtranbot" value="0">';

                        # code...
                    } elseif (!empty($_POST["idtranbot"])) {
                        echo '<input type="hidden" name="idtranbot" value="' . $_POST["idtranbot"] . '">';
                        # code...
                    }
                    ?>

            
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
                     <th>Fecha transacción</th>
                     <th>Realizado por</th>
                     <th>Cliente</th>
                     <th>Categoría</th>
                     <th>Trans lanzadas</th>
                     <th>Trans completadas</th>
                     <th>Tiempo ahorrado</th>







                 </tr>
             </thead>
             <tbody>


                 <?php

                    if (isset($_GET['eliminar'])) {

                        $sqlDelete = "delete from Transaccion_Robot where idtransaccion=?";
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
                            select idtransaccion,fechatr,idPerstr,nombre,idClientetr,nomCliente,idCategoriatr,desCat,botCantrl,botCantrs,tiAhorrado from Transaccion_Robot 
                            inner join usuarios on idPerstr=id
                            inner join Cliente on idClientetr=idCliente
                            inner join Cat_Transaccion on idCategoriatr=idcattr
                            order by fechatr desc";


                    $res = sqlsrv_query($con, $sql);

                    while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {

                        $rutaimg="<IMG src='../assets/img/";
                        $tamañoimg="width='70%' height='30%'";

                        switch ($row["idClientetr"]) {
                            case '1':
                                $cliente = $rutaimg."d1icon.ico".$tamañoimg;
                                break;

                            case '2':
                                $cliente = $rutaimg."bbogota.ico".$tamañoimg;
                                break;

                            case '3':
                                $cliente = $rutaimg."distracom.ico".$tamañoimg ;
                                break;

                            case '4':
                                $cliente = $rutaimg."velez.ico".$tamañoimg ;
                                break;

                            case '5':
                                $cliente = $rutaimg."studiof.ico".$tamañoimg ;
                                break;

                            case '7':
                                $cliente = $rutaimg."colanta.ico".$tamañoimg ;
                                break;

                            case '8':
                                $cliente = $rutaimg."larebaja.ico".$tamañoimg ;
                                break;

                            case '9':
                                $cliente = "GRUPO URIBE";
                                break;

                            case '10':
                                $cliente = $rutaimg."hermeco.ico".$tamañoimg ;
                                break;

                            case '11':
                                $cliente = $rutaimg."leonisa.ico".$tamañoimg ;
                                break;

                            case '12':
                                $cliente = $rutaimg."tcc.ico".$tamañoimg;
                                break;


                            case '13':
                                $cliente = $rutaimg."diag.ico".$tamañoimg;
                                break;


                                case '14':
                                    $cliente=$rutaimg."bbva.ico".$tamañoimg ;
                                break;
    
                                case '15':
                                    $cliente=$rutaimg."av villas.ico".$tamañoimg ;
                                break;
    
                                case '16':
                                    $cliente=$rutaimg."popular.ico".$tamañoimg ;
                                break;
    
                                case '17':
                                    $cliente=$rutaimg."boccidente.ico".$tamañoimg;
                                break;
                                
                                case '18':
                                    $cliente=$rutaimg."porvenir.ico".$tamañoimg ;
                                break;
                                case '19':
                                    $cliente=$rutaimg."pilatos.ico".$tamañoimg;
                                break;
                                case '20':
                                    $cliente=$rutaimg."nca.ico".$tamañoimg;
                                break;
                                case '21':
                                    $cliente=$rutaimg."fds.ico".$tamañoimg;
                                break;

                             


                        }


                        echo "<tr class='text-center texto ' >
                        <td>  <a href='#' class='btn btn-rojo fenergy ' onclick='confirmDeleteTrBot(" . $row["idtransaccion"] . ");'>Eliminar</button></td>
                        <td>
                        <form action='' method='POST'>

                    <input type='hidden' name='idtranbot' value='" . $row["idtransaccion"] . "'>
                       <input type='hidden' name='ftranbot' value='" . $row["fechatr"]->format('Y-m-d') . "'>
                       <input type='hidden' name='idperstr' value='" . $row["idPerstr"] . "'>
                       <input type='hidden' name='name' value='" . $row["nombre"] . "'>
                       <input type='hidden' name='idcliente' value='" . $row["idClientetr"] . "'>
                       <input type='hidden' name='nomcliente' value='" . $row["nomCliente"] . "'>
                       <input type='hidden' name='idcat' value='" . $row["idCategoriatr"] . "'>
                       <input type='hidden' name='descat' value='" . $row["desCat"] . "'>
                       <input type='hidden' name='transl' value='" . $row["botCantrl"] . "'>
                       <input type='hidden' name='transexi' value='" . $row["botCantrs"] . "'>
                       <input type='hidden' name='tiahorrado' value='" . $row["tiAhorrado"] . "'>
                       <input class='btn btn-verde fenergy ' type='submit'  value='Editar/act' name='accion'>
                       </form>
                    
                       </td>
                       
                     
                            <td>" . $row["fechatr"]->format('Y-m-d') . "</td>
                            <td>" . $row["nombre"] . "</td>
                          <td>" . $cliente . "<p style='visibility:hidden'>" . $row["nomCliente"] . "</p></td>
                           
                            <td>" . $row["desCat"] . "</td>
                            <td>" . $row["botCantrl"] . "</td>
                            <td>" . $row["botCantrs"] . "</td>
                            <td>" . $row["tiAhorrado"] . "</td>
                            
                         
                            </tr>";
                    }




                    ?>

     </div>


     </tbody>


     </table>
 </div>