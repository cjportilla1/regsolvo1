<div class="container text-center imgs mt-2  formulario1 p-5 col-10">


    <h1 class="azul titulos ">ASSETS</h1>









    <form class="" action="" method="POST" id="formRegistroUser" ectype="multipart/form-data">


        <div class="form-row">
            <div class="form-group col">
                <label for=""><span class="font-weight-bold titulos">Nombre+modelo</span></label>
                <input name="nameit" type="text" class="form-control" id="nombreid" placeholder="Nombre y modelo" minlength="3" maxlength="60" value="<?php echo $_POST["nameit"]; ?>">
            </div>

            <div class="form-group col">
                <label for=""><span class="font-weight-bold titulos">Serial</span></label>
                <input name="lastnameit" type="text" class="form-control" id="apellid" placeholder="Serial del item" minlength="3" maxlength="60" value="<?php echo $_POST["lastnameit"]; ?>">
            </div>



        </div>

        <div class="form-row">

            <div class="form-group col">

                <label for="inputca"><span class="font-weight-bold">Tipo</span></label>
                <select name="idrol" id="inputcargo" class="form-control">
                    <option value="" disabled> </option>
                    <?php
                    if (empty($_POST["assetype"])) {

                        echo "<option value=''> seleccione--> ";

                        echo "  <option value='1'>Screen</option>";
                        echo " <option value='2'>Keyboard</option>";
                        echo " <option value='3'>Mouse</option>";
                        echo " <option value='4'>Headset</option>";
                        echo " <option value='5'>Camera</option>";
                        echo " <option value='6'>Hard Phone</option>";
                        # code...
                    }
                    ?>
                </select>

            </div>


            <div class="form-group col">

                <label for="inputca"><span class="font-weight-bold">Estado</span></label>

                <select name="idrol" id="inputcargo" class="form-control">
                    <option value="" disabled> </option>
                    <?php
                    if (empty($_POST["assetatus"])) {

                        echo "<option value=''> seleccione--> ";

                        echo "  <option value='1'>Activo</option>";
                        echo " <option value='2'>Nuevo en bodega</option>";
                        echo " <option value='3'>Funcional en bodega</option>";
                        echo " <option value='4'>Equipo con fallas</option>";
                        echo " <option value='5'>Dado de baja</option>";
                        echo " <option value='6'>Home office</option>";
                        # code...
                    }
                    ?>

                </select>
            </div>




        </div>

        <div class="form-row">


            <div class="form-group col">
                <label for="inputca"><span class="font-weight-bold">Sede</span></label>

                <select name="idrol" id="inputcargo" class="form-control">
                    <option value="" disabled> </option>
                    <?php
                    if (empty($_POST["assesite"])) {

                        echo "<option value=''> seleccione--> ";

                        echo "  <option value='1'>Talsa</option>";
                        echo " <option value='2'>Aguacatala</option>";
                        echo " <option value='3'>We work poblado</option>";
                        echo " <option value='4'>We work santa fe</option>";
                        echo " <option value='5'>Tinkko</option>";
                        echo " <option value='6'>Rio sur</option>";
                        echo " <option value='7'>Barranquilla</option>";

                        # code...
                    }
                    ?>
                </select>
            </div>
            <div class=" from-group col">
                <label for=""><span class="font-weight-bold titulos">Soulver</span></label>
                <input name="nameit" type="text" class="form-control" id="nombreid" placeholder="Nombre" minlength="3" maxlength="60" value="<?php echo $_POST["soulver"]; ?>">
            </div>

        </div>


        <div class="form-row">
            <div class="col-4">

            </div>
            <div class="form-group col">

                <label for="inputca"><span class="font-weight-bold">Campaña</span></label>

                <select name="idrol" id="inputcargo" class="form-control">
                    <option value="" disabled> </option>
                    <?php
                    if (empty($_POST["assetcamp"])) {

                        echo "<option value=''> seleccione--> ";

                        echo "  <option value='1'>Talsa</option>";
                        echo " <option value='2'>Aguacatala</option>";
                        echo " <option value='3'>We work poblado</option>";
                        echo " <option value='4'>We work santa fe</option>";
                        echo " <option value='5'>Tinkko</option>";
                        echo " <option value='6'>Rio sur</option>";
                        echo " <option value='7'>Barranquilla</option>";

                        # code...
                    }
                    ?>
                </select>



            </div>
            <!-- <div class="col">
            <label for="inputca"><span class="font-weight-bold">Leer serial</span></label>

            <input class="form-group" type="file" accept="image/*;capture=camera" >
            </div> -->
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
                <th class="titulos">eliminar</th>
                <th class="titulos">Editar</th>
                    <th class="titulos">Nombre y modelo</th>
                    <th class="titulos">Serial</th>
                    <th class="titulos">Tipo</th>
                    <th class="titulos">Estado</th>
                    <th class="titulos">Ubicacion</th>
                    <th class="titulos">Usuario</th>
                    <th class="titulos">Campaña</th>
                    <th class="titulos">ultima modificacion:</th>
                    <th class="titulos">fecha </th>




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


                $sql = "call most_assets";


                $exe = $createcon->query($sql);




                while ($row = $exe->fetch_array()) {

                    switch ($row[4]) {
                        case '1':
                            $estado = "Activo";
                            # code...
                            break;
                        case '2':
                            $estado = "Nuevo en bodega";
                            # code...
                            break;
                        case '3':
                            $estado = "Funcional en bodega";
                            # code...
                            break;
                        case '4':
                            $estado = "Con fallas";
                            # code...
                            break;

                        default:
                            $estado = "De baja";
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
                       
                   

                       <input class='btn btn-verde btn-sm fsolvo' type='submit'  value='Editar/act' name='accion'>
                       </form>
                    
                       </td>
                       
                            <td>" . $row[1] . "</td>
                            <td>" . $row[2] . "</td>
                         
                           
                            <td>" . $row[3] . "</td>
                            <td>" . $estado . "</td>
                            <td>" . $row[5] . "</td>
                            <td>" . $row[6] . "</td>
                            <td>" . $row[7] . "</td>
                            <td>" . $row[8] . "</td>
                            <td>" . $row[9] . "</td>
                         
                            </tr>";
                }




                ?>

    </div>


    </tbody>


    </table>
</div>