/**************************************************************************************************
*                                                                                                 *
* This file is part of HPIPM.                                                                     *
*                                                                                                 *
* HPIPM -- High Performance Interior Point Method.                                                *
* Copyright (C) 2017 by Gianluca Frison.                                                          *
* Developed at IMTEK (University of Freiburg) under the supervision of Moritz Diehl.              *
* All rights reserved.                                                                            *
*                                                                                                 *
* HPIPM is free software; you can redistribute it and/or                                          *
* modify it under the terms of the GNU Lesser General Public                                      *
* License as published by the Free Software Foundation; either                                    *
* version 2.1 of the License, or (at your option) any later version.                              *
*                                                                                                 *
* HPIPM is distributed in the hope that it will be useful,                                        *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                                  *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                                            *
* See the GNU Lesser General Public License for more details.                                     *
*                                                                                                 *
* You should have received a copy of the GNU Lesser General Public                                *
* License along with HPIPM; if not, write to the Free Software                                    *
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA                  *
*                                                                                                 *
* Author: Gianluca Frison, gianluca.frison (at) imtek.uni-freiburg.de                             *
*                                                                                                 *
**************************************************************************************************/

#ifndef HPIPM_D_OCP_QP_H_
#define HPIPM_D_OCP_QP_H_



#include <blasfeo_target.h>
#include <blasfeo_common.h>

#include "hpipm_d_ocp_qp_dim.h"



#ifdef __cplusplus
extern "C" {
#endif



struct d_ocp_qp
	{
	struct d_ocp_qp_dim *dim;
	struct blasfeo_dmat *BAbt;
	struct blasfeo_dvec *b;
	struct blasfeo_dmat *RSQrq;
	struct blasfeo_dvec *rq;
	struct blasfeo_dmat *DCt;
	struct blasfeo_dvec *d;
	struct blasfeo_dvec *Z;
	struct blasfeo_dvec *z;
	int **idxb; // index of box constraints
	int **idxs; // index of soft constraints
	int memsize; // memory size in bytes
	};



//
int d_memsize_ocp_qp(struct d_ocp_qp_dim *dim);
//
void d_create_ocp_qp(struct d_ocp_qp_dim *dim, struct d_ocp_qp *qp, void *memory);
//
void d_cvt_colmaj_to_ocp_qp(double **A, double **B, double **b, double **Q, double **S, double **R, double **q, double **r, int **idxb, double **lb, double **ub, double **C, double **D, double **lg, double **ug, double **Zl, double **Zu, double **zl, double **zu, int **idxs, struct d_ocp_qp *qp);
//
void d_cvt_rowmaj_to_ocp_qp(double **A, double **B, double **b, double **Q, double **S, double **R, double **q, double **r, int **idxb, double **lb, double **ub, double **C, double **D, double **lg, double **ug, double **Zl, double **Zu, double **zl, double **zu, int **idxs, struct d_ocp_qp *qp);
//
void d_update_Q(int stage, double *mat, struct d_ocp_qp *qp);
//
void d_copy_Q(int stage, double *mat, struct d_ocp_qp *qp);
//
void d_update_S(int stage, double *mat, struct d_ocp_qp *qp);
//
void d_copy_S(int stage, double *mat, struct d_ocp_qp *qp);
//
void d_update_R(int stage, double *mat, struct d_ocp_qp *qp);
//
void d_copy_R(int stage, double *mat, struct d_ocp_qp *qp);
//
void d_update_q(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_copy_q(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_update_r(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_copy_r(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_update_A(int stage, double *mat, struct d_ocp_qp *qp);
//
void d_copy_A(int stage, double *mat, struct d_ocp_qp *qp);
//
void d_update_B(int stage, double *mat, struct d_ocp_qp *qp);
//
void d_copy_B(int stage, double *mat, struct d_ocp_qp *qp);
//
void d_update_b(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_copy_b(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_update_lbx(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_copy_lbx(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_update_ubx(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_copy_ubx(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_update_lbu(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_copy_lbu(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_update_ubu(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_copy_ubu(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_update_C(int stage, double *mat, struct d_ocp_qp *qp);
//
void d_copy_C(int stage, double *mat, struct d_ocp_qp *qp);
//
void d_update_D(int stage, double *mat, struct d_ocp_qp *qp);
//
void d_copy_D(int stage, double *mat, struct d_ocp_qp *qp);
//
void d_update_lg(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_copy_lg(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_update_ug(int stage, double *vec, struct d_ocp_qp *qp);
//
void d_copy_ug(int stage, double *vec, struct d_ocp_qp *qp);


#ifdef __cplusplus
}	// #extern "C"
#endif



#endif // HPIPM_D_OCP_QP_H_
