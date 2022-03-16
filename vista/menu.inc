
 <div class="sidebar-header border border-success ">
                <img src="../assets/img/solvologo2.png" alt="" class="w-100 h-100 ">
            </div>

            <ul class="list-unstyled components">
                <p class="titulos"> Módulo interno</p>
            

                <li class="">
                    <a href="#pageSubmenu" data-toggle="collapse" aria-expanded="false" class="dropdown-toggle fsolvo"><i class="fas fa-industry"> Menú </i></a>
                    <ul class="collapse list-unstyled" id="pageSubmenu">
                        <li>
                            <a href="assets.php"><i class="fas fa-key"></i class="titulos"> Assets </a>
                        </li>
                          <li>
                            <a href="qareg1.php"><i class="fas fa-key"></i class="titulos"> Registros QA </a>
                        </li>
                       
                     

                    
                    </ul>
                </li>
              
               
                <li class="">
                    <a href="#homeSubmenu" data-toggle="collapse" aria-expanded="false" class="dropdown-toggle fsolvo"><i class="fas fa-users"></i>  Colaboradores </a>
                    <ul class="collapse list-unstyled" id="homeSubmenu">

                        <?php
if (EMPTY($_SESSION['perf'])) 
{
echo " <h5> Debe ser admin para visualizar esta info</h5>";
    # code...
}elseif ($_SESSION['perf']!='admin') {
    echo " <h5> Debe ser admin para visualizar esta info</h5>";

    # code...
}else {
    echo "  <li>
    <a href='intuser.php'><i class='fas fa-user'></i> <i class='fas fa-list'></i class='titulos'>  Datos personales colaboradores</a>
</li>";
}

                        ?>

                      
                      
                    </ul>

                    <p class="fsolvo"><?php echo "Bienvenido: ".$_SESSION['usnombre']." ".$_SESSION['usapell']." "?></p>
                           <mark> <a href="cerrarsesion.php" class="text-danger btn btn-warning">Cerrar sesión</a> </mark>