/* autogenerated by embedmodel.py.  DO NOT EDIT */

#include <zebra.h>
#include "yang.h"

static const char model[] =
	"module frr-bfdd {\n"
	"  yang-version 1.1;\n"
	"  namespace \"http://frrouting.org/yang/bfdd\";\n"
	"  prefix frr-bfdd;\n"
	"\n"
	"  import ietf-inet-types {\n"
	"    prefix inet;\n"
	"  }\n"
	"  import ietf-yang-types {\n"
	"    prefix yang;\n"
	"  }\n"
	"  import frr-interface {\n"
	"    prefix frr-interface;\n"
	"  }\n"
	"  import frr-route-types {\n"
	"    prefix frr-route-types;\n"
	"  }\n"
	"\n"
	"  organization \"FRRouting\";\n"
	"  contact\n"
	"    \"FRR Users List:       <mailto:frog@lists.frrouting.org>\n"
	"     FRR Development List: <mailto:dev@lists.frrouting.org>\";\n"
	"  description\n"
	"    \"This module defines a model for managing FRR bfdd daemon.\n"
	"\n"
	"     Copyright 2020 FRRouting\n"
	"\n"
	"     Redistribution and use in source and binary forms, with or without\n"
	"     modification, are permitted provided that the following conditions\n"
	"     are met:\n"
	"\n"
	"     1. Redistributions of source code must retain the above copyright notice,\n"
	"     this list of conditions and the following disclaimer.\n"
	"\n"
	"     2. Redistributions in binary form must reproduce the above copyright\n"
	"     notice, this list of conditions and the following disclaimer in the\n"
	"     documentation and/or other materials provided with the distribution.\n"
	"\n"
	"     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS\n"
	"     \\\"AS IS\\\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT\n"
	"     LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR\n"
	"     A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT\n"
	"     HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,\n"
	"     SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT\n"
	"     LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,\n"
	"     DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY\n"
	"     THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT\n"
	"     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE\n"
	"     OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\";\n"
	"\n"
	"  revision 2019-05-09 {\n"
	"    description \"Initial revision.\";\n"
	"    reference\n"
	"      \"RFC 5880: Bidirectional Forwarding Detection (BFD).\n"
	"       RFC 5881: Bidirectional Forwarding Detection (BFD)\n"
	"                 for IPv4 and IPv6 (Single Hop).\n"
	"       RFC 5883: Bidirectional Forwarding Detection (BFD) for Multihop Paths.\";\n"
	"  }\n"
	"\n"
	"\n"
	"  /*\n"
	"   * BFD types declaration.\n"
	"   */\n"
	"  typedef multiplier {\n"
	"    description \"Detection multiplier\";\n"
	"    type uint8 {\n"
	"      range 2..255;\n"
	"    }\n"
	"  }\n"
	"\n"
	"  typedef discriminator {\n"
	"    description \"BFD session identification\";\n"
	"    type uint32 {\n"
	"      range 1..4294967295;\n"
	"    }\n"
	"  }\n"
	"\n"
	"  typedef state {\n"
	"    description \"BFD session state\";\n"
	"    type enumeration {\n"
	"      enum admin-down {\n"
	"        value 0;\n"
	"        description \"Administratively down\";\n"
	"      }\n"
	"      enum down {\n"
	"        value 1;\n"
	"        description \"Down\";\n"
	"      }\n"
	"      enum init {\n"
	"        value 2;\n"
	"        description \"Initializing\";\n"
	"      }\n"
	"      enum up {\n"
	"        value 3;\n"
	"        description \"Up\";\n"
	"      }\n"
	"    }\n"
	"  }\n"
	"\n"
	"  typedef diagnostic {\n"
	"    description \"BFD session diagnostic\";\n"
	"    type enumeration {\n"
	"      enum ok {\n"
	"        value 0;\n"
	"        description \"Ok\";\n"
	"      }\n"
	"      enum control-expired {\n"
	"        value 1;\n"
	"        description \"Control timer expired\";\n"
	"      }\n"
	"      enum echo-failed {\n"
	"        value 2;\n"
	"        description \"Echo function failed\";\n"
	"      }\n"
	"      enum neighbor-down {\n"
	"        value 3;\n"
	"        description \"Neighbor signaled session down\";\n"
	"      }\n"
	"      enum forwarding-reset {\n"
	"        value 4;\n"
	"        description \"Forwarding plane reset\";\n"
	"      }\n"
	"      enum path-down {\n"
	"        value 5;\n"
	"        description \"Path down\";\n"
	"      }\n"
	"      enum concatenated-path-down {\n"
	"        value 6;\n"
	"        description \"Concatenated path down\";\n"
	"      }\n"
	"      enum administratively-down {\n"
	"        value 7;\n"
	"        description \"Administratively down\";\n"
	"      }\n"
	"      enum reverse-concat-path-down {\n"
	"        value 8;\n"
	"        description \"Reverse concatenated path down\";\n"
	"      }\n"
	"    }\n"
	"  }\n"
	"\n"
	"  typedef profile-name {\n"
	"    type string {\n"
	"      length \"1..64\";\n"
	"    }\n"
	"    description \"Profile name format\";\n"
	"  }\n"
	"\n"
	"  typedef profile-ref {\n"
	"    type leafref {\n"
	"      path \"/frr-bfdd:bfdd/frr-bfdd:bfd/frr-bfdd:profile/frr-bfdd:name\";\n"
	"      require-instance false;\n"
	"    }\n"
	"    description \"Reference to a BFD profile\";\n"
	"  }\n"
	"\n"
	"  /*\n"
	"   * Shared BFD items.\n"
	"   */\n"
	"  grouping session-common {\n"
	"    description \"Common BFD session settings\";\n"
	"\n"
	"    leaf detection-multiplier {\n"
	"      type multiplier;\n"
	"      default 3;\n"
	"      description \"Local session detection multiplier\";\n"
	"    }\n"
	"\n"
	"    leaf desired-transmission-interval {\n"
	"      type uint32;\n"
	"      units microseconds;\n"
	"      default 300000;\n"
	"      description \"Minimum desired control packet transmission interval\";\n"
	"    }\n"
	"\n"
	"    leaf required-receive-interval {\n"
	"      type uint32;\n"
	"      units microseconds;\n"
	"      default 300000;\n"
	"      description \"Minimum required control packet receive interval\";\n"
	"    }\n"
	"\n"
	"    leaf administrative-down {\n"
	"      type boolean;\n"
	"      default true;\n"
	"      description \"Disables or enables the session administratively\";\n"
	"    }\n"
	"\n"
	"    leaf passive-mode {\n"
	"      type boolean;\n"
	"      default false;\n"
	"      description\n"
	"        \"Don\'t attempt to start session establishment.\";\n"
	"    }\n"
	"  }\n"
	"\n"
	"  grouping session-echo {\n"
	"    description \"BFD session echo settings\";\n"
	"\n"
	"    leaf echo-mode {\n"
	"      type boolean;\n"
	"      default false;\n"
	"      description \"Use echo packets to detect failures\";\n"
	"    }\n"
	"\n"
	"    leaf desired-echo-transmission-interval {\n"
	"      type uint32;\n"
	"      units microseconds;\n"
	"      default 50000;\n"
	"      description \"Minimum desired control packet transmission interval\";\n"
	"    }\n"
	"  }\n"
	"\n"
	"  grouping session-multi-hop {\n"
	"    description \"BFD session multi hop settings.\";\n"
	"\n"
	"    leaf minimum-ttl {\n"
	"      type uint8 {\n"
	"        range 1..254;\n"
	"      }\n"
	"      description\n"
	"        \"Minimum expected TTL on received packets.\";\n"
	"    }\n"
	"  }\n"
	"\n"
	"  grouping session-states {\n"
	"    /*\n"
	"     * Local settings.\n"
	"     */\n"
	"    leaf local-discriminator {\n"
	"      type discriminator;\n"
	"      description \"Local session identifier\";\n"
	"    }\n"
	"\n"
	"    leaf local-state {\n"
	"      type state;\n"
	"      description \"Local session state\";\n"
	"    }\n"
	"\n"
	"    leaf local-diagnostic {\n"
	"      type diagnostic;\n"
	"      description \"Local session diagnostic\";\n"
	"    }\n"
	"\n"
	"    leaf local-multiplier {\n"
	"      type multiplier;\n"
	"      description \"Local session current multiplier\";\n"
	"    }\n"
	"\n"
	"    /*\n"
	"     * Remote settings.\n"
	"     */\n"
	"    leaf remote-discriminator {\n"
	"      type discriminator;\n"
	"      description \"Remote session identifier\";\n"
	"    }\n"
	"\n"
	"    leaf remote-state {\n"
	"      type state;\n"
	"      description \"Remote session state\";\n"
	"    }\n"
	"\n"
	"    leaf remote-diagnostic {\n"
	"      type diagnostic;\n"
	"      description \"Local session diagnostic\";\n"
	"    }\n"
	"\n"
	"    leaf remote-multiplier {\n"
	"      type multiplier;\n"
	"      description \"Remote session detection multiplier\";\n"
	"    }\n"
	"\n"
	"    /*\n"
	"     * Negotiated settings.\n"
	"     */\n"
	"    leaf negotiated-transmission-interval {\n"
	"      description \"Negotiated transmit interval\";\n"
	"      type uint32;\n"
	"      units microseconds;\n"
	"    }\n"
	"\n"
	"    leaf negotiated-receive-interval {\n"
	"      description \"Negotiated receive interval\";\n"
	"      type uint32;\n"
	"      units microseconds;\n"
	"    }\n"
	"\n"
	"    leaf detection-mode {\n"
	"      description \"Detection mode\";\n"
	"\n"
	"      type enumeration {\n"
	"        enum async-with-echo {\n"
	"          value \"1\";\n"
	"          description \"Async with echo\";\n"
	"        }\n"
	"        enum async-without-echo {\n"
	"          value \"2\";\n"
	"          description \"Async without echo\";\n"
	"        }\n"
	"        enum demand-with-echo {\n"
	"          value \"3\";\n"
	"          description \"Demand with echo\";\n"
	"        }\n"
	"        enum demand-without-echo {\n"
	"          value \"4\";\n"
	"          description \"Demand without echo\";\n"
	"        }\n"
	"      }\n"
	"    }\n"
	"\n"
	"    /*\n"
	"     * Statistics.\n"
	"     */\n"
	"    leaf last-down-time {\n"
	"      type yang:date-and-time;\n"
	"      description \"Time and date of the last time session was down\";\n"
	"    }\n"
	"\n"
	"    leaf last-up-time {\n"
	"      type yang:date-and-time;\n"
	"      description \"Time and date of the last time session was up\";\n"
	"    }\n"
	"\n"
	"    leaf session-down-count {\n"
	"      type uint32;\n"
	"      description \"Number of times the session went down\";\n"
	"    }\n"
	"\n"
	"    leaf session-up-count {\n"
	"      type uint32;\n"
	"      description \"Number of times the session went up\";\n"
	"    }\n"
	"\n"
	"    leaf control-packet-input-count {\n"
	"      type uint64;\n"
	"      description \"Number of control packets received\";\n"
	"    }\n"
	"\n"
	"    leaf control-packet-output-count {\n"
	"      type uint64;\n"
	"      description \"Number of control packets sent\";\n"
	"    }\n"
	"\n"
	"    /*\n"
	"     * Echo mode operational data.\n"
	"     */\n"
	"    leaf negotiated-echo-transmission-interval {\n"
	"      type uint32;\n"
	"      units microseconds;\n"
	"      description \"Negotiated echo transmit interval\";\n"
	"    }\n"
	"\n"
	"    /*\n"
	"     * Statistics.\n"
	"     */\n"
	"    leaf echo-packet-input-count {\n"
	"      type uint64;\n"
	"      description \"Number of echo packets received\";\n"
	"    }\n"
	"\n"
	"    leaf echo-packet-output-count {\n"
	"      type uint64;\n"
	"      description \"Number of echo packets sent\";\n"
	"    }\n"
	"  }\n"
	"\n"
	"  /*\n"
	"   * BFD operational.\n"
	"   */\n"
	"  container bfdd {\n"
	"    container bfd {\n"
	"      presence \"Present if the BFD protocol is enabled\";\n"
	"\n"
	"      list profile {\n"
	"        key \"name\";\n"
	"        description \"BFD pre configuration profiles\";\n"
	"\n"
	"        leaf name {\n"
	"          type profile-name;\n"
	"          description \"Profile name\";\n"
	"        }\n"
	"\n"
	"        uses session-common;\n"
	"        uses session-echo;\n"
	"        uses session-multi-hop;\n"
	"      }\n"
	"\n"
	"      container sessions {\n"
	"        list single-hop {\n"
	"          key \"dest-addr interface vrf\";\n"
	"          description \"List of single hop sessions\";\n"
	"\n"
	"          leaf dest-addr {\n"
	"            type inet:ip-address;\n"
	"            description \"IP address of the peer\";\n"
	"          }\n"
	"\n"
	"          leaf interface {\n"
	"            type string {\n"
	"              length \"0..16\";\n"
	"            }\n"
	"            description \"Interface to use to contact peer\";\n"
	"          }\n"
	"\n"
	"          leaf vrf {\n"
	"            type string;\n"
	"            description \"Virtual Routing Domain name\";\n"
	"          }\n"
	"\n"
	"          leaf source-addr {\n"
	"            type inet:ip-address;\n"
	"            description \"Local IP address\";\n"
	"          }\n"
	"\n"
	"          leaf profile {\n"
	"            type profile-ref;\n"
	"            description \"Override defaults with profile.\";\n"
	"          }\n"
	"\n"
	"          uses session-common;\n"
	"          uses session-echo;\n"
	"\n"
	"          container stats {\n"
	"            uses session-states;\n"
	"            config false;\n"
	"          }\n"
	"        }\n"
	"\n"
	"        list multi-hop {\n"
	"          key \"source-addr dest-addr interface vrf\";\n"
	"          description \"List of multi hop sessions\";\n"
	"\n"
	"          leaf source-addr {\n"
	"            type inet:ip-address;\n"
	"            description \"Local IP address\";\n"
	"          }\n"
	"\n"
	"          leaf dest-addr {\n"
	"            type inet:ip-address;\n"
	"            description \"IP address of the peer\";\n"
	"          }\n"
	"\n"
	"          leaf interface {\n"
	"            type string {\n"
	"              length \"0..16\";\n"
	"            }\n"
	"            description \"Interface to use to contact peer\";\n"
	"          }\n"
	"\n"
	"          leaf vrf {\n"
	"            type string;\n"
	"            description \"Virtual Routing Domain name\";\n"
	"          }\n"
	"\n"
	"          leaf profile {\n"
	"            type profile-ref;\n"
	"            description \"Override defaults with profile.\";\n"
	"          }\n"
	"\n"
	"          uses session-common;\n"
	"          uses session-multi-hop;\n"
	"\n"
	"          container stats {\n"
	"            uses session-states;\n"
	"            config false;\n"
	"          }\n"
	"        }\n"
	"      }\n"
	"    }\n"
	"  }\n"
	"}\n"
	"";

static struct yang_module_embed embed = {
	.mod_name = "frr-bfdd",
	.mod_rev = "2019-05-09",
	.sub_mod_name = "",
	.sub_mod_rev = "",
	.data = model,
	.format = LYS_YANG,
};

static void embed_register(void) __attribute__((_CONSTRUCTOR(2000)));
static void embed_register(void)
{
	yang_module_embed(&embed);
}
