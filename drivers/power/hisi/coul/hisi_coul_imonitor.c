/*
 * hisi_coul_imonitor.c
 *
 * define the imonitor report interface for coul
 *
 * Copyright (c) 2012-2018 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include "hisi_coul_imonitor.h"

/* prepare for imonitor para packet */
static int coul_imonitor_basp_prepare_basic_info(
	struct imonitor_eventobj *obj, void *data);

/* imonitor table list */
static struct coul_imonitor_event_id imonitor_event_id[] = {
	{
		COUL_IMONITOR_BASP_BASIC_INFO,
		COUL_IMONITOR_BASP_BASIC_INFO_NO,
		.prepare_cb = coul_imonitor_basp_prepare_basic_info,
		{.tv_sec = 0, .tv_nsec = 0},
		COUL_IMONITOR_REPORT_INTERVAL_WEEKLY
	},
};

static int coul_imonitor_basp_prepare_basic_info(
	struct imonitor_eventobj *obj, void *data)
{
	return -1;
}

/*
 * Function:        coul_imonitor_get_event_id
 * Description:     get imonitor eventid and prepare callback by type
 * Input:           coul_imonitor_type_t type
 * Output:          NULL
 * Return:          NULL
 */
static unsigned int coul_imonitor_get_event_id(enum coul_imonitor_type type,
	coul_imonitor_prepare_param_cb *prepare)
{}

/*
 * Function:        coul_imonitor_report
 * Description:     report imonitor data
 * Input:           coul_imonitor_type_t type
 * Output:          NULL
 * Return:          NULL
 */
void coul_imonitor_report(enum coul_imonitor_type type, void *data)
{}


/*
 * Function:        coul_imonitor_weekly_report
 * Description:     report imonitor data once a week
 * Input:           coul_imonitor_type_t type
 * Output:          NULL
 * Return:          NULL
 */
void coul_imonitor_periodic_report(enum coul_imonitor_type type, void *data)
{}
