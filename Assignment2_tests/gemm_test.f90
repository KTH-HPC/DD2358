program gemm_test
  use matrix
  implicit none 

  type(matrix_t) :: A, B, C
  real(kind=8), allocatable :: truth(:,:)

  CHARACTER(len=32) :: arg
  type(integer) :: matrix_size = 3 ! default to 3
  integer :: i, j, k

  if (iargc() .gt. 0) then
    call getarg(1, arg)
    read(arg, "(I32)") matrix_size
  end if

  ! init arrays
  call A%init(matrix_size, matrix_size) 
  call B%init(matrix_size, matrix_size) 
  ! call C%init(matrix_size, matrix_size)
  allocate(truth(matrix_size, matrix_size))

  ! fill A and B
  call random_number(A%data)
  call random_number(B%data)

  ! Compute truth
  truth = matmul(A%data, B%data)

  ! Compute matmul
  C = A * B

  ! print out
  print *, "Result:"
  do i = 1,matrix_size
    print *, (C%data(i,j), j=1,matrix_size)
  end do

  print *

  print *, "Truth:"
  do i = 1,matrix_size
    print *, (truth(i,j), j=1,matrix_size)
  end do

  do j = 1,matrix_size
     do i = 1,matrix_size
        if (abs(C%data(i,j) - truth(i,j)) .gt. 1e-12) then
            print *, "Error: (", i, ",", j,") -> C:", C%data(i,j), "; truth:", truth(i,j)
            stop 42
        end if
     end do
  end do

  print *
  print *, "Pass"
end program gemm_test
