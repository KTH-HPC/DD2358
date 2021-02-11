module kernels
implicit none
contains
  subroutine axpy(a, x, y)
    real(kind=8),               intent(in)    :: a
    real(kind=8), dimension(:), intent(in)    :: x
    real(kind=8), dimension(:), intent(inout) :: y
  
    y = a * x + y
  end subroutine
end module kernels

program main
  use, intrinsic :: iso_fortran_env, only : int32, real64
  use kernels
  implicit none
  real(kind=real64)                            :: a
  real(kind=real64), allocatable, dimension(:) :: x
  real(kind=real64), allocatable, dimension(:) :: y

  integer(kind=int32) :: length = 10
  integer(kind=int32) :: i = 10
  allocate(x(length))
  allocate(y(length))

  a = 0.8

  do i = 1, length
    x(i) = 0.5 * i
    y(i) = 0.1 * i
  end do

  do i = 1, length
    print *, a * x(i) + y(i)
  end do
  call axpy(a, x, y)
  print *, y(:)

  deallocate(x)
  deallocate(y)
end program
