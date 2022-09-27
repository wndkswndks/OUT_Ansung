//gps.c


#include"common.h"

/*
 * gps.c
 *
 *  Created on: Nov 15, 2019
 *      Author: Bulanov Konstantin
 *
 *  Contact information
 *  -------------------
 *
 * e-mail   :  leech001@gmail.com
 */

/*
 * |---------------------------------------------------------------------------------
 * | Copyright (C) Bulanov Konstantin,2019
 * |
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * |
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * |---------------------------------------------------------------------------------
 */




GPS_t m_gps;



void GPS_Init()
{
	HAL_UART_Receive_IT(GPS_USART, &m_gps.data, 1);
}

void GPS_config()
{
	uint32_t pastTime = 0;
 	pastTime = HAL_GetTick();
	while(HAL_GetTick() - pastTime <5000)
	{
	  GPS_UART_CallBack();
	}

	m_sx1276.buffCh3[EVENT_GPS_LONGITUDE%8]= (uint16_t)m_gps.nmea_longitude*10000; 
	m_sx1276.buffCh3[EVENT_GPS_LATITUDE%8]= (uint16_t)m_gps.nmea_latitude*10000;


	//PCPrintf("gps_long = %d\r\n",m_sx1276.buffCh3[EVENT_GPS_LONGITUDE%8]);
	//PCPrintf("gps_lati = %d\r\n",m_sx1276.buffCh3[EVENT_GPS_LATITUDE%8]);
	//Event_Config(m_sx1276.buffCh3 ,2);
}
void GPS_UART_CallBack(){
	if (m_gps.data != '\n' && m_gps.cnt < sizeof(m_gps.buff)) {
		m_gps.buff[m_gps.cnt++] = m_gps.data;
	} else {


		if(GPS_validate((char*) m_gps.buff))
			GPS_parse((char*) m_gps.buff);
		m_gps.cnt = 0;
		memset(m_gps.buff, 0, sizeof(m_gps.buff));
	}
	HAL_UART_Receive_IT(GPS_USART, &m_gps.data, 1);
}


int GPS_validate(char *nmeastr){
    char check[3];
    char checkcalcstr[3];
    int i;
    int calculated_check;

    i=0;
    calculated_check=0;

    // check to ensure that the string starts with a $
    if(nmeastr[i] == '$')
        i++;
    else
        return 0;

    //No NULL reached, 75 char largest possible NMEA message, no '*' reached
    while((nmeastr[i] != 0) && (nmeastr[i] != '*') && (i < 75)){
        calculated_check ^= nmeastr[i];// calculate the checksum
        i++;
    }

    if(i >= 75){
        return 0;// the string was too long so return an error
    }

    if (nmeastr[i] == '*'){
        check[0] = nmeastr[i+1];    //put hex chars in check string
        check[1] = nmeastr[i+2];
        check[2] = 0;
    }
    else
        return 0;// no checksum separator found there for invalid

    sprintf(checkcalcstr,"%02X",calculated_check);
    return((checkcalcstr[0] == check[0])
        && (checkcalcstr[1] == check[1])) ? 1 : 0 ;
}

void GPS_parse(char *GPSstrParse){
    if(!strncmp(GPSstrParse, "$GPGGA", 6)){
    	if (sscanf(GPSstrParse, "$GPGGA,%f,%f,%c,%f,%c,%d,%d,%f,%f,%c", &m_gps.utc_time, &m_gps.nmea_latitude, &m_gps.ns, &m_gps.nmea_longitude, &m_gps.ew, &m_gps.lock, &m_gps.satelites, &m_gps.hdop, &m_gps.msl_altitude, &m_gps.msl_units) >= 1){
    		m_gps.dec_latitude = GPS_nmea_to_dec(m_gps.nmea_latitude, m_gps.ns);
    		m_gps.dec_longitude = GPS_nmea_to_dec(m_gps.nmea_longitude, m_gps.ew);
    		return;
    	}
    }
    else if (!strncmp(GPSstrParse, "$GPRMC", 6)){
    	if(sscanf(GPSstrParse, "$GPRMC,%f,%f,%c,%f,%c,%f,%f,%d", &m_gps.utc_time, &m_gps.nmea_latitude, &m_gps.ns, &m_gps.nmea_longitude, &m_gps.ew, &m_gps.speed_k, &m_gps.course_d, &m_gps.date) >= 1)
    		return;

    }
    else if (!strncmp(GPSstrParse, "$GPGLL", 6)){
        if(sscanf(GPSstrParse, "$GPGLL,%f,%c,%f,%c,%f,%c", &m_gps.nmea_latitude, &m_gps.ns, &m_gps.nmea_longitude, &m_gps.ew, &m_gps.utc_time, &m_gps.gll_status) >= 1)
            return;
    }
    else if (!strncmp(GPSstrParse, "$GPVTG", 6)){
        if(sscanf(GPSstrParse, "$GPVTG,%f,%c,%f,%c,%f,%c,%f,%c", &m_gps.course_t, &m_gps.course_t_unit, &m_gps.course_m, &m_gps.course_m_unit, &m_gps.speed_k, &m_gps.speed_k_unit, &m_gps.speed_km, &m_gps.speed_km_unit) >= 1)
            return;
    }
}

float GPS_nmea_to_dec(float deg_coord, char nsew) {
    int degree = (int)(deg_coord/100);
    float minutes = deg_coord - degree*100;
    float dec_deg = minutes / 60;
    float decimal = degree + dec_deg;
    if (nsew == 'S' || nsew == 'W') { // return negative
        decimal *= -1;
    }
    return decimal;
}

void GPS_Enable()
{
	__HAL_UART_ENABLE(&huart2);
}

void GPS_Disable()
{
	__HAL_UART_DISABLE(&huart2);
}

