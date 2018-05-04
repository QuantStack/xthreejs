#ifndef XTHREE_INTERLEAVED_BUFFER_HPP
#define XTHREE_INTERLEAVED_BUFFER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // interleaved_buffer declaration
    //

    template<class D>
    class xinterleaved_buffer : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(buffer_type, derived_type, array);
        XPROPERTY(int, derived_type, stride, 0);
        XPROPERTY(bool, derived_type, dynamic, false);
        XPROPERTY(int, derived_type, version, 0);
        XPROPERTY(bool, derived_type, needsUpdate, false);

        const std::vector<xw::xjson_path_type>& buffer_paths() const;

    protected:

        xinterleaved_buffer();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using interleaved_buffer = xw::xmaterialize<xinterleaved_buffer>;

    using interleaved_buffer_generator = xw::xgenerator<xinterleaved_buffer>;

    //
    // interleaved_buffer implementation
    //

    //
    // buffer_attribute implementation
    //

    template <class D>
    inline const std::vector<xw::xjson_path_type>&  xinterleaved_buffer<D>::buffer_paths() const
    {
        static const std::vector<xw::xjson_path_type> default_buffer_paths = { 
            { "array", "buffer" },
        };
        return default_buffer_paths;
    }

    inline void set_patch_from_property(const decltype(interleaved_buffer::array)& property,
                                        xeus::xjson& patch,
                                        xeus::buffer_sequence& buffers)
    {
        xeus::xjson j = {
            {"shape", property().shape()},
            {"dtype", "float32"},
            {"buffer", xw::xbuffer_reference_prefix() + std::to_string(buffers.size())}
        };
        patch[property.name()] = std::move(j);
        // TODO raw_data -> data upon release 0.16 for xtensor
        buffers.emplace_back(property().raw_data(), 4 * property().size());
    }

    inline void set_property_from_patch(decltype(interleaved_buffer::array)& property,
                                        const xeus::xjson& patch,
                                        const xeus::buffer_sequence& buffers)
    {
        using value_type = typename decltype(interleaved_buffer::array)::value_type;
        std::size_t index = xw::buffer_index(patch[property.name()].template get<std::string>());
        const auto& buffer = buffers[index];
        property = xt::adapt(const_cast<float*>(static_cast<const float*>(buffer.data())),
                             buffer.size() / 4, xt::no_ownership(),
                             std::array<std::size_t, 1>{2});
    }
    
    inline void set_patch_from_property(const decltype(interleaved_buffer_generator::array)& property,
                                        xeus::xjson& patch,
                                        xeus::buffer_sequence& buffers)
    {
        xeus::xjson j = {
            {"shape", property().shape()},
            {"dtype", "float32"},
            {"buffer", xw::xbuffer_reference_prefix() + std::to_string(buffers.size())}
        };
        patch[property.name()] = std::move(j);
        // TODO raw_data -> data upon release 0.16 for xtensor
        buffers.emplace_back(property().raw_data(), 4 * property().size());
    }

    inline void set_property_from_patch(decltype(interleaved_buffer_generator::array)& property,
                                        const xeus::xjson& patch,
                                        const xeus::buffer_sequence& buffers)
    {
        using value_type = typename decltype(interleaved_buffer_generator::array)::value_type;
        std::size_t index = xw::buffer_index(patch[property.name()].template get<std::string>());
        const auto& buffer = buffers[index];
        property = xt::adapt(const_cast<float*>(static_cast<const float*>(buffer.data())),
                             buffer.size() / 4, xt::no_ownership(),
                             std::array<std::size_t, 1>{2});
    }

    template <class D>
    inline void xinterleaved_buffer<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        set_patch_from_property(array, state, buffers);
        xw::set_patch_from_property(stride, state, buffers);
        xw::set_patch_from_property(dynamic, state, buffers);
        xw::set_patch_from_property(version, state, buffers);
        xw::set_patch_from_property(needsUpdate, state, buffers);
    }

    template <class D>
    inline void xinterleaved_buffer<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        set_property_from_patch(array, patch, buffers);
        xw::set_property_from_patch(stride, patch, buffers);
        xw::set_property_from_patch(dynamic, patch, buffers);
        xw::set_property_from_patch(version, patch, buffers);
        xw::set_property_from_patch(needsUpdate, patch, buffers);
    }

    template <class D>
    inline xinterleaved_buffer<D>::xinterleaved_buffer()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xinterleaved_buffer<D>::set_defaults()
    {
        this->_model_name() = "InterleavedBufferModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xinterleaved_buffer));
//}
#endif