// Code generated by protoc-gen-go. DO NOT EDIT.
// source: google/ads/googleads/v1/resources/ad_group_ad_label.proto

package resources

import (
	fmt "fmt"
	math "math"

	proto "github.com/golang/protobuf/proto"
	wrappers "github.com/golang/protobuf/ptypes/wrappers"
	_ "google.golang.org/genproto/googleapis/api/annotations"
)

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.ProtoPackageIsVersion3 // please upgrade the proto package

// A relationship between an ad group ad and a label.
type AdGroupAdLabel struct {
	// The resource name of the ad group ad label.
	// Ad group ad label resource names have the form:
	// `customers/{customer_id}/adGroupAdLabels/{ad_group_id}~{ad_id}~{label_id}`
	ResourceName string `protobuf:"bytes,1,opt,name=resource_name,json=resourceName,proto3" json:"resource_name,omitempty"`
	// The ad group ad to which the label is attached.
	AdGroupAd *wrappers.StringValue `protobuf:"bytes,2,opt,name=ad_group_ad,json=adGroupAd,proto3" json:"ad_group_ad,omitempty"`
	// The label assigned to the ad group ad.
	Label                *wrappers.StringValue `protobuf:"bytes,3,opt,name=label,proto3" json:"label,omitempty"`
	XXX_NoUnkeyedLiteral struct{}              `json:"-"`
	XXX_unrecognized     []byte                `json:"-"`
	XXX_sizecache        int32                 `json:"-"`
}

func (m *AdGroupAdLabel) Reset()         { *m = AdGroupAdLabel{} }
func (m *AdGroupAdLabel) String() string { return proto.CompactTextString(m) }
func (*AdGroupAdLabel) ProtoMessage()    {}
func (*AdGroupAdLabel) Descriptor() ([]byte, []int) {
	return fileDescriptor_2df918faaa4182f5, []int{0}
}

func (m *AdGroupAdLabel) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_AdGroupAdLabel.Unmarshal(m, b)
}
func (m *AdGroupAdLabel) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_AdGroupAdLabel.Marshal(b, m, deterministic)
}
func (m *AdGroupAdLabel) XXX_Merge(src proto.Message) {
	xxx_messageInfo_AdGroupAdLabel.Merge(m, src)
}
func (m *AdGroupAdLabel) XXX_Size() int {
	return xxx_messageInfo_AdGroupAdLabel.Size(m)
}
func (m *AdGroupAdLabel) XXX_DiscardUnknown() {
	xxx_messageInfo_AdGroupAdLabel.DiscardUnknown(m)
}

var xxx_messageInfo_AdGroupAdLabel proto.InternalMessageInfo

func (m *AdGroupAdLabel) GetResourceName() string {
	if m != nil {
		return m.ResourceName
	}
	return ""
}

func (m *AdGroupAdLabel) GetAdGroupAd() *wrappers.StringValue {
	if m != nil {
		return m.AdGroupAd
	}
	return nil
}

func (m *AdGroupAdLabel) GetLabel() *wrappers.StringValue {
	if m != nil {
		return m.Label
	}
	return nil
}

func init() {
	proto.RegisterType((*AdGroupAdLabel)(nil), "google.ads.googleads.v1.resources.AdGroupAdLabel")
}

func init() {
	proto.RegisterFile("google/ads/googleads/v1/resources/ad_group_ad_label.proto", fileDescriptor_2df918faaa4182f5)
}

var fileDescriptor_2df918faaa4182f5 = []byte{
	// 333 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x8c, 0x91, 0xc1, 0x4a, 0xc3, 0x30,
	0x1c, 0xc6, 0x69, 0x87, 0xc2, 0x3a, 0xf5, 0x50, 0x2f, 0x63, 0x0c, 0xd9, 0x94, 0xc1, 0x4e, 0x09,
	0x9d, 0x27, 0xa3, 0x97, 0xec, 0x32, 0x10, 0x91, 0x31, 0xa1, 0x07, 0x29, 0x94, 0x6c, 0x89, 0xa1,
	0xd0, 0x26, 0x25, 0x69, 0xe7, 0xd5, 0x67, 0xf1, 0x22, 0xf8, 0x28, 0x3e, 0x8a, 0x4f, 0x21, 0x6d,
	0x9a, 0xa0, 0x17, 0xf5, 0xf6, 0xb5, 0xff, 0xdf, 0xf7, 0x7d, 0xff, 0x24, 0xc1, 0x15, 0x97, 0x92,
	0xe7, 0x0c, 0x12, 0xaa, 0xa1, 0x91, 0x8d, 0xda, 0x47, 0x50, 0x31, 0x2d, 0x6b, 0xb5, 0x63, 0x1a,
	0x12, 0x9a, 0x72, 0x25, 0xeb, 0x32, 0x25, 0x34, 0xcd, 0xc9, 0x96, 0xe5, 0xa0, 0x54, 0xb2, 0x92,
	0xe1, 0xd4, 0xf0, 0x80, 0x50, 0x0d, 0x9c, 0x15, 0xec, 0x23, 0xe0, 0xac, 0xa3, 0xb1, 0x4d, 0x2f,
	0x33, 0x48, 0x84, 0x90, 0x15, 0xa9, 0x32, 0x29, 0xb4, 0x09, 0x18, 0x9d, 0x75, 0xd3, 0xf6, 0x6b,
	0x5b, 0x3f, 0xc1, 0x67, 0x45, 0xca, 0x92, 0xa9, 0x6e, 0x7e, 0xfe, 0xe6, 0x05, 0x27, 0x98, 0xae,
	0x9a, 0x6e, 0x4c, 0xef, 0x9a, 0xe6, 0xf0, 0x22, 0x38, 0xb6, 0xe9, 0xa9, 0x20, 0x05, 0x1b, 0x7a,
	0x13, 0x6f, 0xde, 0xdf, 0x1c, 0xd9, 0x9f, 0xf7, 0xa4, 0x60, 0xe1, 0x4d, 0x30, 0xf8, 0xb6, 0xf3,
	0xd0, 0x9f, 0x78, 0xf3, 0xc1, 0x62, 0xdc, 0xed, 0x08, 0x6c, 0x1b, 0x78, 0xa8, 0x54, 0x26, 0x78,
	0x4c, 0xf2, 0x9a, 0x6d, 0xfa, 0xc4, 0xf6, 0x84, 0x8b, 0xe0, 0xa0, 0x3d, 0xe5, 0xb0, 0xf7, 0x0f,
	0x9f, 0x41, 0x97, 0x2f, 0x7e, 0x30, 0xdb, 0xc9, 0x02, 0xfc, 0x79, 0x23, 0xcb, 0xd3, 0x9f, 0x07,
	0x5a, 0x37, 0xa1, 0x6b, 0xef, 0xf1, 0xb6, 0x73, 0x72, 0x99, 0x13, 0xc1, 0x81, 0x54, 0x1c, 0x72,
	0x26, 0xda, 0x4a, 0xfb, 0x2c, 0x65, 0xa6, 0x7f, 0x79, 0xa5, 0x6b, 0xa7, 0x5e, 0xfd, 0xde, 0x0a,
	0xe3, 0x77, 0x7f, 0xba, 0x32, 0x91, 0x98, 0x6a, 0x60, 0x64, 0xa3, 0xe2, 0x08, 0x6c, 0x2c, 0xf9,
	0x61, 0x99, 0x04, 0x53, 0x9d, 0x38, 0x26, 0x89, 0xa3, 0xc4, 0x31, 0x9f, 0xfe, 0xcc, 0x0c, 0x10,
	0xc2, 0x54, 0x23, 0xe4, 0x28, 0x84, 0xe2, 0x08, 0x21, 0xc7, 0x6d, 0x0f, 0xdb, 0x65, 0x2f, 0xbf,
	0x02, 0x00, 0x00, 0xff, 0xff, 0xee, 0x8e, 0x14, 0xdd, 0x51, 0x02, 0x00, 0x00,
}
