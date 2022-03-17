<div class="container text-center imgs mt-2  formulario1 p-5 col-10">


    <h1 class="azul titulos ">USUARIOS</h1>









    <form class="" action="" method="POST" id="formRegistroUser" ectype="multipart/form-data">


        <div class="form-row">
            <div class="form-group col">
                <label for=""><span class="font-weight-bold titulos">Nombre</span></label>
                <input name="nameit" type="text" class="form-control" id="nombreid" placeholder="Nombre" minlength="3" maxlength="60" value="<?php echo $_POST["nameit"]; ?>">
            </div>

            <div class="form-group col">
                <label for=""><span class="font-weight-bold titulos">Apellido</span></label>
                <input name="lastnameit" type="text" class="form-control" id="apellid" placeholder="Apellido" minlength="3" maxlength="60" value="<?php echo $_POST["lastnameit"]; ?>">
            </div>



        </div>

        <div class="form-row">

            <div class="form-group col">

                <label for="inputd"><span class="font-weight-bold titulos">Corrreo</span></label>
                <input name="correouit" type="text" class="form-control" id="inputdoc" placeholder="ejemplo@mail.com" minlength="6" pattern="[@]" maxlength="60" value="<?php echo $_POST["correouit"]; ?>">



            </div>


            <div class="form-group col">

                <label for="inputd"><span class="font-weight-bold titulos">Contraseña</span></label>
                <input name="contrasena" type="password" disabled="true" class="form-control" id="inputpass" placeholder="contraseña" minlength="8" maxlength="30" value="<?php echo $_POST["contrasena"]; ?>">


            </div>





        </div>

        <div class="form-row">
            <div class="col-6">
            <label for="inputd"><span class="font-weight-bold titulos">Interpreter ID</span></label>
                <input name="solide" type="text"  class="form-control" id="inputsolid" placeholder="Interpreter ID" minlength="8" maxlength="30" value="<?php echo $_POST["solvide"]; ?>"> 

            </div>

            <div class="col-6"> <button class="btn btn-primary contra" type="button" onclick="mostrarContrasena()">Ver</button>
                <br>
                <input type="checkbox" name="habContra" onclick="habilCont('inputpass')" />
                habilitar contraseña
            </div>

        </div>




        <div class="form-row mb-3">

            <div class="col-4">

            </div>

            <div class="form-group col">
                <label for="inputca"><span class="font-weight-bold">Rol</span></label>
                <select name="idrol" id="inputcargo" class="form-control">
                    <option value="" disabled> </option>
                    <?php
                    if (empty($_POST["idrol"])) {

                        echo "<option value=''> seleccione--> ";

                      echo"  <option value='1'>Administrador</option>";
                       echo" <option value='2'>Supervisor</option>";
                       echo" <option value='3'>Colaborador</option>";
                    
                        # code...
                    } else {

                        if ($_POST["idrol"]==1) {
                            echo "<option value='" . $_POST["idrol"] . "'>Administrador</option> ";
                       
                            echo" <option value='2'>Supervisor</option>";
                            echo" <option value='3'>Colaborador</option>";
                         
                            # code...
                        }else if ($_POST["idrol"]==2) {
                            # code...
                       
                            echo "<option value='" . $_POST["idrol"] . "'>Supervisor</option> ";
                            echo"  <option value='1'>Administrador</option>";
                         
                            echo" <option value='3'>Colaborador</option>";
                          
                       
                            # code...
                        }elseif ($_POST["idrol"]==3) {
                            echo "<option value='" . $_POST["idrol"] . "'>Colaborador</option> ";
                            echo" <option value='2'>Supervisor</option>";
                            echo"  <option value='1'>Administrador</option>";
                          
                            # code...
                        }
                       
                    }
                    ?>
                   




                </select>
            </div>

            <div class="col-4">

            </div>




        </div>



        <div class="form-row">


            <div class="col">

                <button type="button" onclick="cruduserit('guardaruit')" class="btn btn-verde text-light">
                    REGISTRAR </button> <br>
                <br>



            </div>
            <div class="col">
                <button type="button" onclick="resetform()" class="btn btn-verde text-light titulos" id="btnform">
                    Limpiar formulario </button> <br>

            </div>
            <div class="col">

                <button type="button" onclick="cruduserit('actualizaruint')" class="btn btn-verde text-light">
                    ACTUALIZAR </button> <br>

                <article id="alerta" class="alert-warning text-danger"></article>

            </div>




        </div>

        <div class="form-row-12">
            <mark> <a href="cerrarsesion.php" class="text-danger btn btn-warning">Cerrar sesión</a> </mark>
            <?php

            if (empty($_POST["iduint"])) {
                echo '<input type="hidden" name="iduint" value="0">';

                # code...
            } elseif (!empty($_POST["iduint"])) {
                echo '<input type="hidden" name="iduint" value="' . $_POST["iduint"] . '">';
                # code...
            }
            ?>
        </div>


    </form>








</div>


<div class="container mt-5  ">
    <div class="container formulario1 imgs p-5">
        <table id="tusuarios" class="  table-striped " width="100%" height="100%">

            <thead class=" ">
                <tr class=" text-center fverde  fsolvo text-light">
                    <th class="titulos">Eliminar</th>
                    <th class="titulos">Editar</th>
                    <th class="titulos">Nombre</th>
                    <th class="titulos">Apellido</th>
                    <th class="titulos">Mail</th>
                   
                    <th class="titulos">Rol</th>
                    <th class="titulos">Sol ID</th>
                    <th class="titulos">Last login</th>




                </tr>
            </thead>
            <tbody>


                <?php

                if (isset($_GET['eliminar'])) {

                    $sqlDelete = "call del_us(" . $_GET['id'] . ")";
                    $res = $createcon->query($sqlDelete);


                    // while ($fila = $res->fetch_array()) {
                    $fila = $res->fetch_row();

                    // print_r($fila);

                    // if ($row[0]=1) {
                    //     echo "<label class='text-danger' >usuario eliminado correctamente</label>";
                    // } else {
                    //     echo "<label class='text-danger' >usuario admin,no se puede eliminar</label>";
                    // }
                    // }
                }


                $sql = "call mostr_usrs";


                $exe = $createcon->query($sql);




                while ($row = $exe->fetch_array()) {

                  switch ($row[5]) {
                      case '1': $showrol="Administrador";
                          # code...
                          break;
                          case '2': $showrol="Supervisor";
                          # code...
                          break;
                          case '3': $showrol="Colaborador";
                          # code...
                          break;
                          case '4': $showrol="Practicante IT";
                          # code...
                          break;
                      
                      default:
                         $showrol="visual";
                          break;
                  }
                    echo "<tr class='text-center texto ' >
                        <td>  <a href='#' class='btn btn-rojo btn-sm fsolvo' onclick='confirmDeleteUint(" . $row[0] . ");'>Eliminar</button></td>
                        <td>
                        <form action='' method='POST'>
                        <input type='hidden' name='iduint' value='" . $row[0] . "'>
                        <input type='hidden' name='nameit' value='" . $row[1] . "'>
                       <input type='hidden' name='lastnameit' value='" . $row[2] . "'>
                       <input type='hidden' name='correouit' value='" . $row[3] . "'>
                       <input type='hidden' name='contrasena' value='" . $row[4] . "'>
                       <input type='hidden' name='idrol' value='" . $row[5] . "'>
                       <input type='hidden' name='solvide' value='" . $row[6] . "'>
                       
                       
                   

                       <input class='btn btn-verde btn-sm fsolvo' type='submit'  value='Editar/act' name='accion'>
                       </form>
                    
                       </td>
                       
                            <td>" . $row[1] . "</td>
                            <td>" . $row[2] . "</td>
                         
                           
                            <td>" . $row[3] . "</td>
                          
                            <td>" . $showrol . "</td>
                            <td>" . $row[6] . "</td>
                            <td>" . $row[7] . "</td>
                         
                            </tr>";
                }




                ?>

    </div>


    </tbody>


    </table>
</div>