   <div class="container mt-5  ">
  
                <div class="container formulario1 imgs p-5 text-center" >
                <h1 class="verde titulos ">Usuarios internos empresas</h1>
                
               
                    <table id="tusuarios" class="responsive  table-striped " width="100%" height="100%">
                        <thead class=" ">
                            <tr class=" text-center fverde   text-light">
                              
                                <th>Razon social</th>
                                <th>Usuario</th>
                                <th>Contraseña</th>
                                <th>Rol</th>




                            </tr>
                        </thead>
                        <tbody>


                            <?php

                         


                            $sql = "	
                        select iduint,razons,usuarioint,passuint,roluint,descrol from Usersint ui 
                            inner join Roluint on roluint=idroluint";


                            $res = sqlsrv_query($con, $sql);




                            while ($row = sqlsrv_fetch_array($res, SQLSRV_FETCH_BOTH)) {
                                echo "<tr class='text-center texto ' >
                    
                     
                       
                            <td>" . $row["razons"] . "</td>
                            <td>" . $row["usuarioint"] . "</td>
                            <td>" . $row["passuint"] . "</td>
                           
                            <td>" . $row["descrol"] . "</td>
                         
                            </tr>";



                                // echo $row["nombre"];
                            }




                            ?>



                </div>


                </tbody>


                </table>
                <div class="form-row-12">
                        <mark> <a href="cerrarsesion.php" class="text-danger btn btn-warning font-size:1rem">Cerrar sesion</a> </mark>

                    </div>
            </div>