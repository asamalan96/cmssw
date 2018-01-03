#include "EventFilter/RPCRawToDigi/interface/RPCAMCLinkEvents.h"

#include "EventFilter/RPCRawToDigi/interface/RPCAMCLinkEvent.h"

RPCAMCLinkEvents::RPCAMCLinkEvents()
{}

std::string RPCAMCLinkEvents::getEventName(unsigned int id)
{
    switch (id & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)) {
        // from FED CDF Header and Trailer
    case (fed_event_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("FED Event"); break;
    case (fed_header_check_fail_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Header check fail"); break;
    case (fed_header_id_mismatch_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Header FED ID mismatch"); break;
    case (fed_trailer_check_fail_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Trailer check fail"); break;
    case (fed_trailer_length_mismatch_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Trailer length mismatch"); break;
    case (fed_trailer_crc_mismatch_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Trailer CRC mismatch"); break;
        // from AMC13 Header
    case (fed_amc13_block_incomplete_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Incomplete AMC13 data"); break;
        // from AMC13 AMC Header
    case (fed_amc13_amc_number_invalid_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Invalid AMC number"); break;
    case (amc_amc13_block_incomplete_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Incomplete AMC13 data"); break;

    case (amc_event_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("AMC Event"); break;
    case (amc_amc13_evc_bc_invalid_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("AMC EvC or BC invalid"); break;
    case (amc_amc13_length_incorrect_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("AMC incorrect block length"); break;
    case (amc_amc13_crc_mismatch_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("AMC CRC mismatch"); break;
    case (amc_amc13_size_inconsistent_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("AMC payload size inconsistent"); break;
    case (amc_payload_incomplete_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Incomplete AMC payload"); break;
        // from AMC Payload Header
    case (amc_number_mismatch_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("AMC number mismatch"); break;
    case (amc_size_mismatch_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("AMC size mismatch"); break;
        // from RPC Record
    case (amc_link_invalid_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Invalid Link"); break;

    case (input_event_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Input Event"); break;
    case (input_link_error_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Link error"); break;
    case (input_link_ack_fail_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Link ack fail"); break;
    case (input_eod_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("EOD"); break;
    case (input_lb_invalid_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Invalid LB"); break;
    case (input_connector_invalid_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Invalid Connector"); break;
    case (input_connector_not_used_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
        return std::string("Connector not used"); break;
        /*
          case ((input_bc_mismatch_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
          return std::string("BC Mismatch"); break;
          case ((input_bc0_mismatch_ & (RPCAMCLinkEvent::event_mask_ | RPCAMCLinkEvent::group_mask_)):
          return std::string("BC0 Mismatch"); break;
        */

    default:
        return std::string("unknown"); break;
    }
}
