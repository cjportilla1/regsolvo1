<nav class="navbar navbar-expand-lg navbar-light ">

    <div class="container-fluid">

        <button type="button" id="sidebarCollapse" class="btn btn-info">
            <i class="fas fa-align-left"></i>
            <span>Menú</span>
        </button>

    </div>

</nav>

<div class="container-fluid mt-5 col-10 formulario1 imgs  p-4 ">

  <h1 class="verde titulos ">Datos personales de empleados</h1>
    
        <table id="tusuarios" class=" responsive  table-striped " width="100%" height="100%">
            <thead class=" ">
                <tr class="  text-center  fverde text-light">

                    <th>Nombre</th>
                    <th>Documento</th>
                    <th>Cargo</th>
                    <th>Telefono</th>
                    <th>Contacto</th>
                    <th>tel cont</th>
                    <th>Rh</th>
                    <th>Direccion</th>
                    <th>T.doc</th>
                    <th>Fnaci</th>
                    <th>C.natal</th>
                    <th>reside</th>
                    <th>Med.trans</th>
                    <th>Genero</th>
                    <th>Fecha.ing</th>


                </tr>
            </thead>
            <tbody>


                <?php




                $sql = "	
                    select id,nombre,cedula as documento,descripcion,idtipodoc,fnacimiento,nomCiudad as lnacimineto,idciudad,cargo,tel,contactp,telconta,nomCiudad as lresidencia,direccion,rh,mtransporte,genero,fechaing from usuarios u 
                    inner join TipoDocumento on tipodoc= idtipodoc
                    inner join Ciudad on ciudadn = idciudad";


                $res = sqlsrv_query($con, $sql);




                while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {
                    echo "<tr class='text-center texto ' >
                      
                       
                            <td>" . $row["nombre"] . "</td>
                            <td>" . $row["documento"] . "</td>
                            <td>" . $row["cargo"] . "</td>
                            <td>" . $row["tel"] . "</td>
                            <td>" . $row["contactp"] . "</td>
                            <td>" . $row["telconta"] . "</td>
                            <td>" . $row["rh"] . "</td>
                            <td>" . $row["direccion"] . "</td>
                            <td>" . $row["descripcion"] . "</td>
                            <td>" . $row["fnacimiento"]->format('Y-m-d') . "</td>
                            <td>" . $row["lnacimineto"] . "</td>
                            <td>" . $row["lresidencia"] . "</td>
                            <td>" . $row["mtransporte"] . "</td>
                            <td>" . $row["genero"] . "</td>
                            <td>" . $row["fechaing"]->format('Y-m-d') . "</td>
                            </tr>";
                }




                ?>




            </tbody>
            <!-- <?php print_r($_SESSION); ?> -->


        </table>
        <mark> <a href="cerrarsesion.php" class="text-danger  btn btn-warning">Cerrar sesion</a> </mark>
   
</div>