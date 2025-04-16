<?php
    trait Circle{
        private float $radius=1.0;
        private string $color="red";

        public function __construct(float $radius,string $color){
            $this->setRadius($radius);
            $this->color=$color;
        }

        function getRadius():float{
            return $this->radius;
        }
        function getColor():string{
            return $this->color;
        }
        function setRadius(float $radius):void{
            $this->radius=$radius;
        }
        function setColor(string $color):void{
            $this->color=$color;
        }
        function getArea():float{
            return $this->radius * $this->radius*3.14;
        }
        public function __toString():string{
            return "Circle(radius={$this->radius}, color={$this->color})";
        }
    }
    class Cylinder{
        use Circle;
        private float $height=5.0; 
        public function __construct(float $radius,float $height,string $color){
            $this->setHeight($height);
            $this->setRadius($radius);
            $this->setColor($color);
        }
        function getHeight():float{
            return $this->height;
        }
        function setHeight(float $height):void{
            $this->height=$height;
        }
        function getVolume():float{
            return ($this->height*$this->height*$this->height);
        }
    }
    $cylin =new Cylinder(5,10,"red");
    echo $cylin->getVolume();

?>