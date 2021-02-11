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
