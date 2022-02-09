
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
                            <a href="comerc.php"><i class="fas fa-industry"></i class="titulos"> Comercializadores   </a>
                        </li>
                     

                    
                    </ul>
                </li>
              
               
                <li class="">
                    <a href="#homeSubmenu" data-toggle="collapse" aria-expanded="false" class="dropdown-toggle fsolvo"><i class="fas fa-users"></i>  Colaboradores </a>
                    <ul class="collapse list-unstyled" id="homeSubmenu">
                        <li>
                            <a href="formulario.php"><i class="fas fa-user"></i> <i class="fas fa-list"></i class="titulos">  Datos personales colaboradores</a>
                        </li>
                      
                    </ul>

                    <p class="fsolvo"><?php echo "Bienvenido: ".$_SESSION['usnombre']." ".$_SESSION['usapell']." "?></p>