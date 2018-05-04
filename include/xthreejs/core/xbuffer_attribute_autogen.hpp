#ifndef XTHREE_BUFFER_ATTRIBUTE_HPP
#define XTHREE_BUFFER_ATTRIBUTE_HPP

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
    // buffer_attribute declaration
    //

    template<class D>
    class xbuffer_attribute : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(buffer_type, derived_type, array);
        XPROPERTY(bool, derived_type, dynamic, false);
        XPROPERTY(bool, derived_type, needsUpdate, false);
        XPROPERTY(bool, derived_type, normalized, true);
        XPROPERTY(int, derived_type, version, -1);

        const std::vector<xw::xjson_path_type>& buffer_paths() const;

    protected:

        xbuffer_attribute();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using buffer_attribute = xw::xmaterialize<xbuffer_attribute>;

    using buffer_attribute_generator = xw::xgenerator<xbuffer_attribute>;

    //
    // buffer_attribute implementation
    //

    //
    // buffer_attribute implementation
    //

    template <class D>
    inline const std::vector<xw::xjson_path_type>&  xbuffer_attribute<D>::buffer_paths() const
    {
        static const std::vector<xw::xjson_path_type> default_buffer_paths = { 
            { "array", "buffer" },
        };
        return default_buffer_paths;
    }

    inline void set_patch_from_property(const decltype(buffer_attribute::array)& property,
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

    inline void set_property_from_patch(decltype(buffer_attribute::array)& property,
                                        const xeus::xjson& patch,
                                        const xeus::buffer_sequence& buffers)
    {
        using value_type = typename decltype(buffer_attribute::array)::value_type;
        std::size_t index = xw::buffer_index(patch[property.name()].template get<std::string>());
        const auto& buffer = buffers[index];
        property = xt::adapt(const_cast<float*>(static_cast<const float*>(buffer.data())),
                             buffer.size() / 4, xt::no_ownership(),
                             std::array<std::size_t, 1>{2});
    }
    
    inline void set_patch_from_property(const decltype(buffer_attribute_generator::array)& property,
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

    inline void set_property_from_patch(decltype(buffer_attribute_generator::array)& property,
                                        const xeus::xjson& patch,
                                        const xeus::buffer_sequence& buffers)
    {
        using value_type = typename decltype(buffer_attribute_generator::array)::value_type;
        std::size_t index = xw::buffer_index(patch[property.name()].template get<std::string>());
        const auto& buffer = buffers[index];
        property = xt::adapt(const_cast<float*>(static_cast<const float*>(buffer.data())),
                             buffer.size() / 4, xt::no_ownership(),
                             std::array<std::size_t, 1>{2});
    }

    template <class D>
    inline void xbuffer_attribute<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        set_patch_from_property(array, state, buffers);
        xw::set_patch_from_property(dynamic, state, buffers);
        xw::set_patch_from_property(needsUpdate, state, buffers);
        xw::set_patch_from_property(normalized, state, buffers);
        xw::set_patch_from_property(version, state, buffers);
    }

    template <class D>
    inline void xbuffer_attribute<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        set_property_from_patch(array, patch, buffers);
        xw::set_property_from_patch(dynamic, patch, buffers);
        xw::set_property_from_patch(needsUpdate, patch, buffers);
        xw::set_property_from_patch(normalized, patch, buffers);
        xw::set_property_from_patch(version, patch, buffers);
    }

    template <class D>
    inline xbuffer_attribute<D>::xbuffer_attribute()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xbuffer_attribute<D>::set_defaults()
    {
        this->_model_name() = "BufferAttributeModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xbuffer_attribute));
//}
#endif