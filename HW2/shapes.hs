class Shape s where
  area      :: s -> Double
  perimeter :: s -> Double

data Circle = Circle Double

instance Shape Circle where
  area (Circle radius) =
    pi * radius * radius

  perimeter (Circle radius) =
    2 * pi * radius
