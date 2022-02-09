<?php

// autoload_static.php @generated by Composer

namespace Composer\Autoload;

class ComposerStaticInitabe816ff8dbf30b6e031852cdc647b79
{
    public static $files = array (
        '941748b3c8cae4466c827dfb5ca9602a' => __DIR__ . '/..' . '/rmccue/requests/library/Deprecated.php',
    );

    public static $prefixLengthsPsr4 = array (
        'W' => 
        array (
            'WpOrg\\Requests\\' => 15,
        ),
        'P' => 
        array (
            'PHPMailer\\PHPMailer\\' => 20,
        ),
    );

    public static $prefixDirsPsr4 = array (
        'WpOrg\\Requests\\' => 
        array (
            0 => __DIR__ . '/..' . '/rmccue/requests/src',
        ),
        'PHPMailer\\PHPMailer\\' => 
        array (
            0 => __DIR__ . '/..' . '/phpmailer/phpmailer/src',
        ),
    );

    public static $prefixesPsr0 = array (
        'U' => 
        array (
            'Ubidots' => 
            array (
                0 => __DIR__ . '/..' . '/ubidots/ubidots/src',
            ),
        ),
    );

    public static $classMap = array (
        'Composer\\InstalledVersions' => __DIR__ . '/..' . '/composer/InstalledVersions.php',
        'Requests' => __DIR__ . '/..' . '/rmccue/requests/library/Requests.php',
    );

    public static function getInitializer(ClassLoader $loader)
    {
        return \Closure::bind(function () use ($loader) {
            $loader->prefixLengthsPsr4 = ComposerStaticInitabe816ff8dbf30b6e031852cdc647b79::$prefixLengthsPsr4;
            $loader->prefixDirsPsr4 = ComposerStaticInitabe816ff8dbf30b6e031852cdc647b79::$prefixDirsPsr4;
            $loader->prefixesPsr0 = ComposerStaticInitabe816ff8dbf30b6e031852cdc647b79::$prefixesPsr0;
            $loader->classMap = ComposerStaticInitabe816ff8dbf30b6e031852cdc647b79::$classMap;

        }, null, ClassLoader::class);
    }
}
