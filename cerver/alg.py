from ctypes import c_int

jwt_alg_t = c_int

JWT_ALG_NONE = 0
JWT_ALG_HS256 = 1
JWT_ALG_HS384 = 2
JWT_ALG_HS512 = 3
JWT_ALG_RS256 = 4
JWT_ALG_RS384 = 5
JWT_ALG_RS512 = 6
JWT_ALG_ES256 = 7
JWT_ALG_ES384 = 8
JWT_ALG_ES512 = 9
JWT_ALG_TERM = 10
