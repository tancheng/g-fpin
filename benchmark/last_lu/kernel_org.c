# this is fortran but it is easy to understand; sum is reduction and dble is int to double conversion
do m = 1, 5
	sum(m) = sqrt ( sum(m) / ( dble(nx0-2)*dble(ny0-2)*dble(nz0-2) ) )
end do
