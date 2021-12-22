 <nav class="navbar navbar-expand-lg navbar-light ">

     <div class="container-fluid">

         <button type="button" id="sidebarCollapse" class="btn btn-info">
             <i class="fas fa-align-left"></i>
             <span>Menú</span>
         </button>

     </div>

 </nav>

 <div class="container col-10 text-center imgs mt-2 formulario1">
     <h3 class="verde titulos">Ingresar nuevo comercializador</h3>
     <div class="row">


         <div class="form-group col-md-4">
             <form action="" class="" method="POST" id="formComer">
                 <label for="inputcomerci"><span class="font-weight-bold fenergy">Nuevo Comercializador</span></label>

         </div>
         <div class="form-group col-md-4">
             <input name="nomnucom" type="text" value="" class="form-control" id="inputnucom" placeholder="Nombre del nuevo comercializador">
         </div>

         <div class="form-group col-md-4">

             <button type="button" onclick="crudcomer('insNuComer')" class="btn btn-verde text-light titulos">
                 Registrar </button>

         </div>
         </form>
     </div>

 </div>
 <div class="container col-10 text-center imgs mt-2  formulario1 ">


     <h1 class="verde titulos ">Comercializadores</h1>



     <section class="row justify-content-center p-3 ">





         <form class="" action="" method="POST" id="formRegistroUser" ectype="multipart/form-data">


             <div class="form-row">
                 <div class="form-group col-md-3">
                     <label for="inputgender"><span class="font-weight-bold fenergy">Comercializador</span></label>
                     <select name="idnomcom" id="inputcomer" class="form-control">
                     <option value="" disabled> </option>
                         <?php
                            if (empty($_POST["idnomcom"])) {

                                echo "<option value=''> Seleccione--> ";
                                # code...
                            } else {
                                echo "<option value='" . $_POST["idnomcom"] . "'>" . $_POST["nomcomer"] . " ";
                            }
                            ?>
                         </option>

                         <?php
                            $sql = "select * from Nom_Comerci order by nomComer asc";
                            $res = sqlsrv_query($con, $sql);

                            while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {
                                echo '<option value="' . $row[0] . '">' . $row[1] . '</option>';
                            }
                            ?>

                     </select>
                 </div>
                 <div class="form-group col-md-3">
                     <label for="inputgender"><span class="font-weight-bold fenergy">Servicio</span></label>
                     <select name="servicom" id="inputServcomer" class="form-control">
                     <option value="" disabled> </option>
                         <?php
                            if (empty($_POST["servicom"])) {

                                echo "<option value=''> Seleccione--> ";
                                # code...
                            } else {
                                echo "<option value='" . $_POST["servicom"] . "'>" . $_POST["servicom"] . " ";
                            }
                            ?>
                         </option>
                         <option value="Energía">Energía</option>
                         <option value="Acueducto">Acueducto</option>
                         <option value="Gas">Gas</option>
                         <option value="Energía/Acueducto">Energía/Acueducto</option>
                         <option value="Energía/Gas">Energía/Gas</option>
                         <option value="Gas/Acueducto">Gas/Acueducto</option>
                         <option value="Energía/Gas/Acueducto">Energía/Gas/Acueducto</option>




                     </select>
                 </div>

                 <div class="form-group col-md-3">
                     <label for="inputtel"><span class="font-weight-bold">Cuenta</span></label>
                     <input name="cuentacom" type="text" value="<?php echo $_POST["cuentacom"]; ?>" class="form-control" id="inputcuenta" placeholder="Cuenta">
                 </div>

                 <div class="form-group col-md-3">
                     <label for="inputtel"><span class="font-weight-bold fenergy">Nota</span></label>
                     <textarea name="notacom" type="text" class="form-control" id="inputnota" placeholder="observaciones"><?php echo $_POST["notacom"]; ?></textarea>
                 </div>



             </div>
             <div class="form-row">

                 <div class="form-group col-md-3">
                     <label for="inputtel"><span class="font-weight-bold fenergy">Clave</span></label>
                     <input name="clavecom" disabled="true" type="password" value="<?php echo $_POST["clavecom"]; ?>" class="form-control" id="inputpasscomer" minlength="8" maxlength="30" placeholder="Clave">
                     <button class="btn btn-primary" type="button" onclick="mostrarContrasena()">Ver</button>
                     <br>
                     <input type="checkbox" name="habContra" onclick="habilCont('inputpasscomer')" />
                     habilitar contraseña
                 </div>

                 <div class="form-group col-md-3">
                     <label for="inputtel"><span class="font-weight-bold fenergy">Link pag web</span></label>
                     <input name="linkcom" type="text" value="<?php echo $_POST["linkcom"]; ?>" class="form-control" id="inputlink" placeholder="https:// ejemplo.com" min="1000000" max="999999999999">
                 </div>



                 <div class="form-group col-md-3">
                     <label for="inputtel"><span class="font-weight-bold fenergy">Correo</span></label>
                     <input name="correocom" type="email" value="<?php echo $_POST["correocom"]; ?>" class="form-control" id="inputmail" placeholder="ejemplo@mail.com" pattern="(@)" >
                 </div>



                 <div class="form-group col-md-3">
                     <label for="inputtel"><span class="font-weight-bold fenergy">Telefono</span></label>
                     <input name="telecom" type="text" value="<?php echo $_POST["telecom"]; ?>" class="form-control" id="inputTel" placeholder="#Teléfono" title="Solo se aceptan estos simbolos (-) y números">
                 </div>






             </div>

             <div class="form-row-12 mb-3">
             <div class="alert alert-danger" role="alert">
  Recuerda: Si el registro solo tiene link  web de contacto,debes probarlo luego de guardarlo!
</div>

             </div>





             <div class="form-row">

                 <div class="col-2"> </div>
                 <div class="col">

                     <button type="button" onclick="cruduser('guardarcomer')" class="btn btn-verde text-light titulos">
                         REGISTRAR </button> <br>
                     <br>

                 </div>

                 <div class="col">
                <button type="button" onclick="resetform()" class="btn btn-verde text-light titulos" id="btnform">
                       Limpiar formulario </button> <br>

                </div>
                 <div class="col">

                     <button type="button" onclick="cruduser('actualizarcomer')" class="btn btn-verde text-light titulos">
                         ACTUALIZAR </button> <br>

                     <article id="alerta" class="alert-warning text-danger"></article>

                 </div>


                 <div class="col-2"> </div>

             </div>

             <div class="form-row-12">
                 <mark> <a href="cerrarsesion.php" class="text-danger btn btn-warning">Cerrar sesion</a> </mark>
                 <?php

                    if (empty($_POST["idcomer"])) {
                        echo '<input type="hidden" name="idcomer" value="0">';

                        # code...
                    } elseif (!empty($_POST["idcomer"])) {
                        echo '<input type="hidden" name="idcomer" value="' . $_POST["idcomer"] . '">';
                        # code...
                    }
                    ?>

                 <!-- <?php print_r($_SESSION); ?> -->
             </div>


         </form>



     </section>




 </div>

 <div class="container mt-5 col-12 ">
     <div class="container formulario1 imgs p-4">
         <table id="tusuarios" class=" table-striped tabla  " width="100%">

             <thead class=" ">
                 <tr class=" text-center fverde fenergy  text-light">
                     <th>Eliminar</th>
                     <th>Editar</th>
                     <th>Comercializador</th>
                     <th>Servicio</th>
                     <th>Nota</th>
                     <th>Cuenta</th>


                     <th>Link</th>
                     <th>Correo</th>
                     <th>Telefono</th>







                 </tr>
             </thead>
             <tbody>


                 <?php

                    if (isset($_GET['eliminar'])) {

                        $sqlDelete = "delete from Comercializador where idComerc=?";
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
                    select idComerc,idnomCom,nomComer,serviCom,notaCom,cuentaCom,claveCom,linkCom,correoCom,teleCom  from Comercializador 
                    inner join Nom_Comerci on idnomCom=idNomComer
                    order by coModDate desc";


                    $res = sqlsrv_query($con, $sql);




                    while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {

                        if ($row["linkCom"] == 'null') {
                            $enlace = "no hay página";
                            $link = "null";
                            $color = "text-danger";
                        } else {
                            $link = $row["linkCom"];
                            $enlace = "Link página web";
                            $color = "text-primary";
                        }
                        echo "<tr class='text-center textop ' >
                        <td>  <a href='#' class='btn btn-rojo fenergy btn-sm' onclick='confirmDeleteComer(" . $row["idComerc"] . ");'>Eliminar</button></td>
                        <td>
                        <form action='' method='POST'>
                        <input type='hidden' name='idcomer' value='" . $row["idComerc"] . "'>
                         <input type='hidden' name='idnomcom' value='" . $row["idnomCom"] . "'>
                         <input type='hidden' name='nomcomer' value='" . $row["nomComer"] . "'>
                        <input type='hidden' name='servicom' value='" . $row["serviCom"] . "'>
                       <input type='hidden' name='notacom' value='" . $row["notaCom"] . "'>
                    
                       <input type='hidden' name='cuentacom' value='" . $row["cuentaCom"] . "'>
                       <input type='hidden' name='clavecom' value='" . $row["claveCom"] . "'>
                       <input type='hidden' name='linkcom' value='" . $row["linkCom"] . "'>
                       <input type='hidden' name='correocom' value='" . $row["correoCom"] . "'>
                       <input type='hidden' name='telecom' value='" . $row["teleCom"] . "'>
                      
                       <input class='btn btn-verde fenergy btn-sm' type='submit'  value='Editar/act' name='accion'>
                       </form>
                    
                       </td>
                       
                
                        
                            <td >" . $row["nomComer"] . "</td>
                            <td>" . $row["serviCom"] . "</td>
                            <td >" . $row["notaCom"] . "</td>
                            <td>" . $row["cuentaCom"] . "</td>
                       
                            <td class='" . $color . "'><a href='" . $link . "' target='blank'>" . $enlace . "</a></td>
                            <td>" . $row["correoCom"] . "</td>
                            <td>" . $row["teleCom"] . "</td>
                         
                            </tr>";
                    }




                    ?>



     </div>


     </tbody>


     </table>
 </div>