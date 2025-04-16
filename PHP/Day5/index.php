<?php 
require('Connection.php')

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet"
    href="https://cdnjs.cloudflare.com/ajax/libs/bootstrap-icons/1.11.1/font/bootstrap-icons.min.css">
    <link href='https://unpkg.com/boxicons@2.1.4/css/boxicons.min.css' rel='stylesheet'>
    <title>Home Page</title>
</head>
<body>
    <!-- =============== NavBar ============ -->
    <nav class="navbar navbar-expand-lg bg-white shadow-sm fixed-top">
        <div class="container">
            <a class="navbar-brand fs-3 fw-bolder text-primary" href="#">WebSite</a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarNav">
                <ul class="navbar-nav ms-auto fs-5">
                    <li class="nav-item me-4"><a class="nav-link active fw-bold text-primary" href="#">Home</a></li>
                    <li class="nav-item me-4"><a class="nav-link" href="#mywork">My Work</a></li>
                    <li class="nav-item me-4"><a class="nav-link" href="#">About Me</a></li>
                    <li class="nav-item me-4"><a class="nav-link" href="#">Contact Me</a></li>
                </ul>
            </div>
        </div>
    </nav>
</body>
</html>