module math
  interface
    real(c_double) function c_product(a, b) bind(c, name="product")
      use iso_c_binding
      implicit none
      real(kind=c_double), value :: a
      real(kind=c_double), value :: b
    end function
  end interface
end module

subroutine times(c, a, b)
  use, intrinsic :: iso_c_binding, only: c_double 
  use math
  use iso_fortran_env, only : real64
  real(kind=real64), intent(in)  :: a
  real(kind=real64), intent(in)  :: b
  real(kind=real64), intent(out) :: c
  c = c_product(a, b)
end subroutine

subroutine add(c, a, b)
  use iso_fortran_env, only : real64
  real(kind=real64), intent(in)  :: a
  real(kind=real64), intent(in)  :: b
  real(kind=real64), intent(out) :: c
  c = a + b
end subroutine

program main
  use iso_fortran_env, only : real64
  real(kind=real64) :: a
  real(kind=real64) :: b
  real(kind=real64) :: c
  real(kind=real64) :: d
  
  a = 0.5
  b = 0.5
  
  call add(c, a, b)
  call times(d, a, b)
  
  print *, a, " + ",  b, " = ", c
  print *, a, " * ",  b, " = ", d
end program
