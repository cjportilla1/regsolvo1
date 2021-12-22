<nav class="navbar navbar-expand-lg navbar-light ">

                <div class="container-fluid">

                    <button type="button" id="sidebarCollapse" class="btn btn-info">
                        <i class="fas fa-align-left"></i>
                        <span>Menú</span>
                    </button>

                </div>

            </nav>
            <div class="container col-10 text-center imgs mt-2  formulario1">


                <h1 class="verde titulos ">Registro datos personales de colaboradores</h1>



                <section class="row justify-content-center p-4">





                    <form class="" action="" method="POST" id="formRegistroUser" ectype="multipart/form-data">


                        <div class="form-row">
                            <div class="form-group col-md-2">
                                <label for=""><span class="font-weight-bold">Nombre completo</span></label>
                                <input name="nombre" type="text" class="form-control" id="nombreid" placeholder="Nombre" minlength="3" maxlength="40" value="<?php echo $_POST["nombre"]; ?>">
                            </div>

                            <div class="form-group col-md-2">
                                <label for="inputd"><span class="font-weight-bold">Documento</span></label>
                                <input name="cedula" type="number" class="form-control" id="inputdoc" placeholder="#Cedula" min="1000000" max="999999999999" minlength="7" maxlength="12" value="<?php echo $_POST["cedula"]; ?>">
                            </div>

                            <div class="form-group col-md-2">
                                <label for="inputca"><span class="font-weight-bold">Rol</span></label>
                                <select name="cargo" id="inputcargo" class="form-control">
                                    <?php
                                    if (empty($_POST["cargo"])) {

                                        echo "<option value=''> seleccione--> ";
                                        # code...
                                    } else {
                                        echo "<option value='" . $_POST["cargo"] . "'>" . $_POST["cargo"] . " ";
                                    }
                                    ?>
                                    <option value="Desarrollador">Desarrollador</option>
                                    <option value="Chief operating officer">Chief operating officer</option>
                                    <option value="Sales manager colombia">Sales manager colombia</option>
                                    <option value="Auxiliar administrativo">Auxiliar administrativo</option>
                                    <option value="Abogada">Abogad@</option>
                                    <option value="Analista de centralización">Analista de centralización</option>
                                    <option value="Líder de gestión">Líder de gestión</option>
                                    <option value="Analista de auditoría">Analista de auditoría</option>
                                    <option value="International sales director">International sales director</option>
                                    <option value="Analista financiera">Analista financiera</option>



                                </select>
                            </div>
                            <div class="form-group col-md-3">
                            <label for=""><span class="font-weight-bold">Nombre equipo(pc)</span></label>
                                <input name="computador" type="text" class="form-control" id="nombreid" placeholder="nombre equipo asignado " minlength="3" maxlength="40" value="<?php echo $_POST["computador"]; ?>">

                            </div>
                            <div class="form-group col-md-3">
                            <label for=""><span class="font-weight-bold">Cuenta padre equipo</span></label>
                            <select name="idemail" id="inputcargo" class="form-control">
                            <?php
                                    if (empty($_POST["idemail"])) {

                                        echo "<option value=''> seleccione--> ";
                                        # code...
                                    } else {
                                        echo "<option value='" . $_POST["idemail"] . "'>" . $_POST["mailenergy"] . " ";
                                    }
                                    ?>
                            <?php
                                    $sql = "SELECT * from EM_mail";
                                    $res = sqlsrv_query($con, $sql);

                                    while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {
                                        echo '<option value="' . $row[0] . '">' . $row[1] . '</option>';
                                    }
                                    ?>
                            </select>

                            </div>




                        </div>
                        <div class="form-row">





                            <div class="form-group col-md-2">
                                <label for="inpu"><span class="font-weight-bold">Fecha nacimiento</span></label>
                                <input type="date" value="<?php echo $_POST["fnacimiento"]; ?>" class="form-control " id="inputbplace" name="fnacimiento" placeholder="fnacimi" <?php echo 'max=' . date('Y-m-d') ?> <?php echo 'min=' . date('(Y-18)-m-d') ?>>
                            </div>

                            <div class="form-group col-md-2 ">
                                <label for="inputca"><span class="font-weight-bold">Ciudad actual</span></label>
                                <select name="cresidencia" id="inputcresi" class="form-control">
                                    <?php
                                    if (empty($_POST["cresidencia"])) {
                                        echo "<option value=''> seleccione->";
                                        # code...
                                    } else {
                                        echo "<option value='" . $_POST["cresidencia"] . "' >" . $_POST["cresidencia1"] . "  ";
                                    }
                                    ?>
                                    </option>
                                    <?php
                                    $sql = "SELECT * from Ciudad";
                                    $res = sqlsrv_query($con, $sql);

                                    while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {
                                        echo '<option value="' . $row[0] . '">' . $row[1] . '</option>';
                                    }
                                    ?>

                                </select>

                            </div>

                            <div class="form-group col-md-2">
                                <label for="inputca"><span class="font-weight-bold">Ciu nacimiento</span></label>
                                <select name="cnacimiento" id="inputcnaci" class="form-control" placeholder="seleccione">

                                    <?php
                                    if (empty($_POST["cnacimiento"])) {
                                        echo "<option value=''> seleccione->";
                                        # code...
                                    } else {
                                        echo "<option value='" . $_POST["cnacimiento"] . "' >" . $_POST["cnacimiento1"] . "  ";
                                    }
                                    ?> </option>

                                    <?php
                                    $sql = "SELECT * from Ciudad";
                                    $res = sqlsrv_query($con, $sql);

                                    while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {
                                        echo '<option value="' . $row[0] . '">' . $row[1] . '</option>';
                                    }
                                    ?>
                                </select>
                            </div>

                            <div class="form-group col-md-2">
                                <label for="inpu"><span class="font-weight-bold">Fecha ingreso EM</span></label>
                                <input type="date" value="<?php echo $_POST["fingreso"]; ?>" class="form-control " id="inputfingreso" name="fingreso" placeholder="fingreso" <?php echo 'max=' . date('Y-m-d') ?>>
                            </div>

                            <div class="form-group col-md-2 ">
                                <label for="inputtel"><span class="font-weight-bold">Teléfono</span></label>
                                <input name="telefono" type="number" value="<?php echo $_POST["telefono"]; ?>" class="form-control" id="inputTel" placeholder="#telefono" min="1000000" max="999999999999" minlength="7" maxlength="12">
                            </div>

                            <div class="form-group col-md-2">
                                <label for="inputcontact"><span class="font-weight-bold">Nom contacto</span></label>
                                <input name="contacto" type="text" value="<?php echo $_POST["contacto"]; ?>" class="form-control" id="inputA" placeholder="Primer y segundo apellido" minlength="3" maxlength="30">
                            </div>



                        </div>
                        <div class="form-row">



                            <div class="form-group col-md-2">
                                <label for="inputcontactphone"><span class="font-weight-bold">Tel contacto</span></label>
                                <input name="telefonoc" type="number" value="<?php echo $_POST["telefonoc"]; ?>" class="form-control" id="inputTelc" placeholder="#tel contacto" minlength="7" maxlength="12" max="9999999999" min="1111111">
                            </div>

                            <div class="form-group col-md-2">
                                <label for="inputRh"><span class="font-weight-bold">RH</span></label>
                                <select name="rhsanguineo" value="" id="inputrole" class="form-control">

                                    <?php
                                    if (empty($_POST["rhsanguineo"])) {
                                        echo "<option value=''> seleccione->";
                                        # code...
                                    } else {
                                        echo " <option value='" . $_POST["rhsanguineo"] . "'> " . $_POST["rhsanguineo"] . "";
                                    }

                                    ?>

                                    </option>
                                    <option value="O+">O+</option>
                                    <option value="O-">O-</option>
                                    <option value="A+">A+</option>
                                    <option value="A-">A-</option>
                                    <option value="B+">B+</option>
                                    <option value="B-">B-</option>
                                    <option value="AB+">AB+</option>
                                    <option value="AB-">AB-</option>
                                </select>
                            </div>

                            <div class="form-group col-md-2">
                                <label for="inputState"><span class="font-weight-bold">T documento</span></label>
                                <select name="idTipoDoc" id="inputDoctype" class="form-control">
                                    <?php
                                    if (empty($_POST["idTipoDoc"])) {

                                        echo "<option value=''> seleccione--> ";
                                        # code...
                                    } else {
                                        echo "<option value='" . $_POST["idTipoDoc"] . "'>" . $_POST["descdoc"] . " ";
                                    }
                                    ?>
                                    </option>
                                    <option value="1">Cédula de ciudadanía</option>
                                    <option value="2">Tarjeta de identidad</option>
                                    <option value="3">Cédula extranjero</option>

                                </select>
                            </div>
                            <div class="form-group col-sm-2">
                                <label for="inputmtransport"><span class="font-weight-bold">Transporte</span></label>
                                <select name="medtransporte" id="inputmtrans" class="form-control">
                                    <?php
                                    if (empty($_POST["medtransporte"])) {

                                        echo "<option value=''> seleccione--> ";
                                        # code...
                                    } else {
                                        echo "<option value='" . $_POST["medtransporte"] . "'>" . $_POST["medtransporte"] . " ";
                                    }
                                    ?>
                                    </option>
                                    <option value="Moto">Moto</option>
                                    <option value="Público automotor">Público automotor</option>
                                    <option value="Privado automotor">Privado automotor</option>
                                    <option value="Público metro">Público metro</option>
                                  
                                 


                                </select>

                            </div>

                            <div class="form-group col-md-2">
                                <label for="inputAddress"><span class="font-weight-bold">Dirección</span></label>
                                <input name="direccion" value="<?php echo $_POST["direccion"]; ?>" type="text" class="form-control" id="inputdireccion" placeholder="Cra ejemplo 123 #321 B" minlength="5" maxlength="30">
                            </div>

                            <div class="form-group col-md-2">
                                <label for="inputgender"><span class="font-weight-bold">Género</span></label>
                                <select name="genero" id="inputgender" class="form-control">
                                    <?php
                                    if (empty($_POST["genero"])) {

                                        echo "<option value=''> Seleccione--> ";
                                        # code...
                                    } else {
                                        echo "<option value='" . $_POST["genero"] . "'>" . $_POST["genero"] . " ";
                                    }
                                    ?>
                                    </option>
                                    <option value="Masculino">Masculino</option>
                                    <option value="Femenino">Femenino</option>
                                    <option value="otro">otro</option>


                                </select>
                            </div>



                        </div>





                        <div class="form-row">

                            <div class="col-4"></div>
                            <div class="col">

                                <button type="button" onclick="cruduser('guardar')" class="btn btn-verde text-light">
                                    REGISTRAR </button> <br>
                                <br>



                            </div>
                            <div class="col">

                                <button type="button" onclick="cruduser('actualizar')" class="btn btn-verde text-light">
                                    ACTUALIZAR </button> <br>

                                <article id="alerta" class="alert-warning text-danger"></article>

                            </div>


                            <div class="col-4">



                            </div>

                        </div>

                        <div class="form-row-12">
                        <mark> <a href="cerrarsesion.php" class="text-danger btn btn-warning">Cerrar sesión</a> </mark>
                          
                           <!-- <?php print_r($_SESSION); ?> -->
                        </div>


                    </form>



                </section>




            </div>


            <div class="container mt-5 col-12 ">
                <div class="container formulario1 imgs p-4">
                    <table id="tusuarios" class=" table-striped " width="100%" height="100%">
                        <thead class=" ">
                            <tr class=" text-center fverde   text-light">
                                <th>Eliminar</th>
                                <th>Editar</th>
                                <th>Nombre</th>
                                <th>Documento</th>
                                <th>Cargo</th>
                                <th>Equipo</th>
                                <th>Teléfono</th>
                                <th>Rh</th>
                                <th>Contacto</th>
                                <th>Tel contac</th>
                             
                                <th>Dirección</th>



                                <th>Tipo de doc</th>
                                <th>Fecha nacimiento</th>
                                <th>Ciudad natal</th>
                                <th>ciudad residencia</th>
                                <th>Medio de transporte</th>
                                <th>Género</th>
                                <th>Fecha de ingreso</th>
                                <th>Email cuenta padre</th>


                            </tr>
                        </thead>
                        <tbody>


                            <?php

                            if (isset($_GET['eliminar'])) {

                                $sqlDelete = "exec borrar ?";
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
                    select id,nombre,cedula as documento,descripcion,idtipodoc,fnacimiento,nomCiudad as lnacimineto,idciudad,cargo,tel,contactp,telconta,nomCiudad as lresidencia,direccion,rh,mtransporte,genero,fechaing,comp,idMail,desEmail from usuarios u 
                    inner join TipoDocumento on tipodoc= idtipodoc
                    inner join Ciudad on ciudadn = idciudad
                    inner join EM_mail on fk_cuentap=idMail";


                            $res = sqlsrv_query($con, $sql);




                            while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {
                                echo "<tr class='text-center texto ' >
                        <td>  <a href='#' class='btn btn-rojo  fenergy' onclick='confirmDelete(" . $row["id"] . ");'>Eliminar</button></td>
                        <td>
                        <form action='' method='POST'>

                       <input type='hidden' name='nombre' value='" . $row["nombre"] . "'>
                       <input type='hidden' name='cedula' value='" . $row["documento"] . "'>
                       <input type='hidden' name='cargo' value='" . $row["cargo"] . "'>
                       <input type='hidden' name='telefono' value='" . $row["tel"] . "'>
                       <input type='hidden' name='contacto' value='" . $row["contactp"] . "'>
                       <input type='hidden' name='telefonoc' value='" . $row["telconta"] . "'>
                       <input type='hidden' name='rhsanguineo' value='" . $row["rh"] . "'>
                       <input type='hidden' name='direccion' value='" . $row["direccion"] . "'>
                       <input type='hidden' name='idTipoDoc' value='" . $row["idtipodoc"] . "'>
                       <input type='hidden' name='fnacimiento' value='" . $row["fnacimiento"]->format('Y-m-d') . "'>
                       <input type='hidden' name='cnacimiento' value='" . $row["idciudad"] . "'>
                       <input type='hidden' name='cresidencia' value='" . $row["idciudad"] . "'>
                       <input type='hidden' name='medtransporte' value='" . $row["mtransporte"] . "'>
                       <input type='hidden' name='genero' value='" . $row["genero"] . "'>
                       <input type='hidden' name='fingreso' value='" . $row["fechaing"]->format('Y-m-d') . "'>
                       <input type='hidden' name='cnacimiento1' value='" . $row["lnacimineto"] . "'>
                       <input type='hidden' name='cresidencia1' value='" . $row["lresidencia"] . "'>
                       <input type='hidden' name='descdoc' value='" . $row["descripcion"] . "'>
                       <input type='hidden' name='computador' value='" . $row["comp"] . "'>
                       <input type='hidden' name='idemail' value='" . $row["idMail"] . "'>
                       <input type='hidden' name='mailenergy' value='" . $row["desEmail"] . "'>

                       <input class='btn btn-verde  fenergy' type='submit'  value='Editar/act' name='accion'>
                       </form>
                    
                       </td>
                       
                            <td>" . $row["nombre"] . "</td>
                            <td>" . $row["documento"] . "</td>
                            <td>" . $row["cargo"] . "</td>
                            <td>" . $row["comp"] . "</td>
                            <td>" . $row["tel"] . "</td>
                            <td>" . $row["rh"] . "</td>
                            <td>" . $row["contactp"] . "</td>
                            <td>" . $row["telconta"] . "</td>
                           
                            <td>" . $row["direccion"] . "</td>

                           
                            <td>" . $row["descripcion"] . "</td>
                            <td>" . $row["fnacimiento"]->format('Y-m-d') . "</td>
                            <td>" . $row["lnacimineto"] . "</td>
                            <td>" . $row["lresidencia"] . "</td>
                           
                            <td>" . $row["mtransporte"] . "</td>
                            <td>" . $row["genero"] . "</td>
                            <td>" . $row["fechaing"]->format('Y-m-d') . "</td>
                            <td>" . $row["desEmail"] . "</td>
                          
                           
                            </tr>";
                            }




                            ?>

                </div>


                </tbody>


                </table>
            </div>